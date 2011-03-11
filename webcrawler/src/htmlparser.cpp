#include "htmlparser.h"
#include "url.h"
#include "pagesparsed.h"
#include "utils.h"

#include <stdlib.h>
#include "string.h"

// cs240utils headers
#include "URLInputStream.h"
#include "HTMLTokenizer.h"

using namespace std;

int stopWordsComparator(const void* first, const void* second){
	string sKey = *(string*)first;
	string sElem = *(string*)second;

	return sKey.compare(sElem);
}

HTMLParser::HTMLParser(string& tURL){
	this->tUrl = tURL;
}

void HTMLParser::parseText(string text, KeywordIndex* pIndex, string* pStopWords, int iStopWords){
	string tCopy = string(text.c_str());

	// stupid checkstyle hack
	string delimiter = "";
	delimiter.append(" \n\t\r!#$%'()*+,./:;<=>?@[\\]^`{|}~¡¢£¤¥¦§¨©ª«¬®¯°±²³´");
	delimiter.append("¶\"·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéê");
	delimiter.append("ëìíîïðñòóôõö÷øùúûüýþÿŒœŠšŸƒ–—‘’‚“”„†‡•…‰⁈⁘&µ");

	char* sToken = strtok((char*)tCopy.c_str(), (char*)delimiter.c_str());

	while(sToken){
		string tKey = myToLower(sToken);
		// must start with an alphabat letter
		if(tKey[0] >= 97 || tKey[0] <= 122){
			// if it isn't in the stopwords file, then add it to the index
			if(!bsearch(&tKey, pStopWords, iStopWords, sizeof(string*), stopWordsComparator)){
				pIndex->put(tKey, this->tUrl);
			}
		}
		sToken = strtok(NULL, (char*)delimiter.c_str());
	}
}

Page* HTMLParser::parse(PageQueue* pQueue, PagesParsed* pParsed, KeywordIndex* pIndex,
						string* pStopWords, int iStopWords){
	Page* pPage = new Page;
	pPage->pURL = this->tUrl;

	URLInputStream tStream = URLInputStream(this->tUrl);
	HTMLTokenizer tTokenizer = HTMLTokenizer(&tStream);
	bool bTitle = false;
	bool bIgnore = false;
	bool bIndex = false;
	while(tTokenizer.HasNextToken()){
		HTMLToken tToken = tTokenizer.GetNextToken();
		switch(tToken.GetType()){
			case TAG_START:{
				string tokenValue = myToLower(tToken.GetValue());

				// awesome checkstyle hacks
				bTitle = tokenValue.compare("title") == 0 ? true : bTitle;
				bIgnore = tokenValue.compare("script") == 0 ? true : bIgnore;
				bIndex = tokenValue.compare("body") == 0 ? true : bIndex;
				if(tokenValue.compare("a") == 0){
					string href = tToken.GetAttribute("href");
					this->addLink(href, pQueue, pParsed);
				}
				break;
			}

			case TAG_END:{
				string tokenValue = myToLower(tToken.GetValue());
				// awesome checkstyle hacks
				bTitle = tokenValue.compare("title") == 0 ? false : bTitle;
				bIgnore = tokenValue.compare("script") == 0 ? false : bIgnore;
				bIndex = tokenValue.compare("body") == 0 ? false : bIndex;
				break;
			}

			case TEXT:{
				if(bTitle){
					pPage->description = string(tToken.GetValue());
				}

				if(bTitle || bIndex){
					parseText(tToken.GetValue(), pIndex, pStopWords, iStopWords);
				}
				break;
			}

			case COMMENT: // we don't care...
			case END:
			default:{
				break;
			}
		}
	}

	pParsed->Insert(pPage, NULL);

	return pPage;
}

bool HTMLParser::addLink(std::string tURL, PageQueue* pQueue, PagesParsed* pParsed){
	// we don't care about fragments
	if(tURL[0] == '#'){
		return false;
	}

	if(!URL::isRelative(tURL)){
		// check the net_loc
		URL base = URL(this->tUrl);
		URL next = URL(tURL);
		if(base.domainMatches(&next) && base.pathMatches(&next)){
			return true;
		}
		return false;
	}

	// check the path
	URL base = URL(this->tUrl);
	string sNewURL = base.resolve(tURL);

	size_t tPos = sNewURL.rfind("/");
	if(this->tUrl.compare(0, tPos, sNewURL)){
		string tExt = base.getExtension();
		if(tExt == "html" || tExt == "htm" || tExt == "shtml" ||
			tExt == "cgi" || tExt == "jsp" || tExt == "asp" ||
			tExt == "aspx" || tExt == "php" || tExt == "pl" ||
			tExt == "cfm"){

			// get rid of query or fragment
			string urlToAdd = sNewURL;
			tPos = urlToAdd.find('#');
			if(tPos > 0){
				urlToAdd = urlToAdd.substr(0, tPos);
			}

			if(!pParsed->pageProcessed(urlToAdd)){
				pQueue->push(urlToAdd);
				return true;
			}
			return false;
		}
	}
	return false;
}
