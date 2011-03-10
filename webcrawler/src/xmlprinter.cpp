#include <sstream>

#include "xmlprinter.h"
#include "string"
#include "url.h"
#include "pagesparsed.h"
#include "keywordindex.h"

using namespace std;

string XMLPrinter::generateXML(string startURL, PagesParsed* pPages, KeywordIndex* pIndex){
	string sReturn = "";
	sReturn += "<website>";

	sReturn += "<start-url>";
	sReturn += startURL;
	sReturn += "</start-url>";

	sReturn += "<pages>";
	LLNode* pNode = pPages->GetFirst();
	while(pNode){
		Page* pPage = (Page*)pNode->GetValue();
		sReturn += generatePageXML(pPage);

		pNode = pNode->GetNext();
	}
	sReturn += "</pages>";


	sReturn += "<index>";
	pIndex->recurse(generateKeywordXML, (void*)&sReturn);
	sReturn += "</index>";

	sReturn += "</website>";
	return sReturn;
}

std::string XMLPrinter::generatePageXML(Page* pPage){
	string sReturn = "<page>";

	sReturn += "<url>";
	sReturn += pPage->pURL;
	sReturn += "</url>";

	sReturn += "<description>";
	sReturn += pPage->description;
	sReturn += "</description>";

	sReturn += "</page>";

	return sReturn;
}

void XMLPrinter::generateKeywordXML(Occurrence* pOccurrence, void* pData){
	string* pReturn = (string*)pData;
	pReturn->append("<word>");

	pReturn->append("<value>");
	pReturn->append(pOccurrence->word);
	pReturn->append("</value>");

	pOccurrence->recurse(generateOccurrenceXML, pData);

	pReturn->append("</word>");
}

void XMLPrinter::generateOccurrenceXML(Instance* pInstance, void* pData){
	string* pReturn = (string*)pData;
	pReturn->append("<occurrence>");

	pReturn->append("<url>");
	pReturn->append(pInstance->url);
	pReturn->append("</url>");

	pReturn->append("<count>");
	std::stringstream ss;
	ss << pInstance->count;
	pReturn->append(ss.str());
	pReturn->append("</count>");

	pReturn->append("</occurrence>");
}
