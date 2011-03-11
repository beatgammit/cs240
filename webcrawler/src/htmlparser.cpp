#include "htmlparser.h"

using namespace std;

int stopWordsComparator(const void* first, const void* second){
	string sKey = *(string*)first;
	string sElem = *(string*)second;

	return sKey.compare(sElem);
}

int numNonWhitespace(string s){
	int iCount = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] != ' '){
			iCount++;
		}
	}
	return iCount;
}

int indexOfIthNonWhitespace(string s, int iTH){
	int iCount = 0;
	int i = 0;
	for(i = 0; i < s.length() && iCount < iTH; i++){
		if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\r'){
			iCount++;
		}
	}
	return i;
}

HTMLParser::HTMLParser(string& tURL, string baseURL){
	this->tUrl = tURL;
	this->baseURL = baseURL;
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
		string tKey = StringUtil::ToLowerCopy(sToken);
		// must start with an alphabat letter
		if(tKey[0] >= 97 && tKey[0] <= 122){
			// if it isn't in the stopwords file, then add it to the index
			if(!bsearch(&tKey, pStopWords, iStopWords, sizeof(string*), stopWordsComparator)){
				pIndex->put(tKey, this->tUrl);
			}
		}
		sToken = strtok(NULL, (char*)delimiter.c_str());
	}
}

Page* fixupPage(string description, string url, string lastResort){
	if(description == "" && lastResort.length()){
		description = lastResort.substr(0, indexOfIthNonWhitespace(lastResort, 100));
	}

	// fixes memory leak when exception is thrown
	Page* pPage = new Page;
	pPage->description = description;
	pPage->url = url;

	return pPage;
}

Page* HTMLParser::parse(PageQueue* pQueue, PagesParsed* pParsed, KeywordIndex* pIndex,
						string* pStopWords, int iStopWords){
	string description = "";
	string lastResort = "";

	URLInputStream tStream = URLInputStream(this->tUrl);
	HTMLTokenizer tTokenizer = HTMLTokenizer(&tStream);

	bool bTitle = false, bIgnore = false, bBody = false, bReadDesc = false;
	while(tTokenizer.HasNextToken()){
		HTMLToken tToken = tTokenizer.GetNextToken();
		switch(tToken.GetType()){
			case TAG_START:{
				string tokenValue = StringUtil::ToLowerCopy(tToken.GetValue());

				// awesome checkstyle hacks
				bTitle = tokenValue.compare("title") == 0 ? true : bTitle;
				bIgnore = tokenValue.compare("script") == 0 ? true : bIgnore;
				bBody = tokenValue.compare("body") == 0 ? true : bBody;
				if(tokenValue.compare("a") == 0 && tToken.AttributeExists("href")){
					string href = tToken.GetAttribute("href");
					this->addLink(href, pQueue, pParsed);
				}else if(description == "" && tokenValue[0] == 'h' && tokenValue.length() < 4){
					bReadDesc = (tokenValue[1] <= 57 && tokenValue[1] >= 48) ? true : bReadDesc;
				}
				break;
			}

			case TAG_END:{
				string tokenValue = StringUtil::ToLowerCopy(tToken.GetValue());
				// awesome checkstyle hacks
				bTitle = tokenValue.compare("title") == 0 ? false : bTitle;
				bIgnore = tokenValue.compare("script") == 0 ? false : bIgnore;
				bBody = tokenValue.compare("body") == 0 ? false : bBody;
				bReadDesc = tokenValue[0] == 'h' ? false : bReadDesc;
				break;
			}

			case TEXT:{
				if(bTitle || bReadDesc){
					description = description == "" ? string(tToken.GetValue()) : description;
					bReadDesc = false;

					parseText(tToken.GetValue(), pIndex, pStopWords, iStopWords);
				}else if(description == ""){
					lastResort += numNonWhitespace(lastResort) < 100 ? tToken.GetValue() : "";

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

	Page* pPage = fixupPage(description, this->tUrl, lastResort);

	pParsed->add(pPage);

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
			if(tURL != this->tUrl && !pParsed->pageProcessed(tURL) && !pQueue->contains(tURL)){
				pQueue->push(tURL);
				return true;
			}
			return false;
		}
		return false;
	}

	// check the path
	URL base = URL(this->tUrl);
	string sNewURL = base.resolve(tURL);

	size_t tPos = this->baseURL.rfind("/");

	if(this->baseURL.compare(0, tPos, sNewURL, 0, tPos) == 0){
		string tExt = base.getExtension();
		if(tExt == "html" || tExt == "htm" || tExt == "shtml" ||
			tExt == "cgi" || tExt == "jsp" || tExt == "asp" ||
			tExt == "aspx" || tExt == "php" || tExt == "pl" ||
			tExt == "cfm"){

			// get rid of query or fragment
			string urlToAdd = sNewURL;
			tPos = urlToAdd.find('#');
			if(tPos != string::npos){
				urlToAdd.erase(tPos);
			}

			if(this->tUrl != urlToAdd && !pParsed->pageProcessed(urlToAdd) && !pQueue->contains(urlToAdd)){
				pQueue->push(urlToAdd);
				return true;
			}
			return false;
		}
	}
	return false;
}
