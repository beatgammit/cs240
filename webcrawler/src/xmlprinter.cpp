#include <sstream>

#include "xmlprinter.h"
#include "string"
#include "url.h"
#include "pagesparsed.h"
#include "keywordindex.h"
#include "StringUtil.h"

using namespace std;

string XMLPrinter::generateXML(string startURL, PagesParsed* pPages, KeywordIndex* pIndex){
	string sReturn = "";
	sReturn += "<website>\n";

	sReturn += "<start-url>";
	sReturn += startURL;
	sReturn += "</start-url>\n";

	sReturn += "<pages>\n";
	LLNode* pNode = pPages->GetFirst();
	while(pNode){
		Page* pPage = (Page*)pNode->GetValue();
		sReturn += generatePageXML(pPage);

		pNode = pNode->GetNext();
	}
	sReturn += "</pages>\n";


	sReturn += "<index>";
	pIndex->recurse(generateKeywordXML, (void*)&sReturn);
	sReturn += "</index>\n";

	sReturn += "</website>";
	return sReturn;
}

std::string XMLPrinter::generatePageXML(Page* pPage){
	string sReturn = "<page>\n";

	sReturn += "<url>";
	sReturn += pPage->url;
	sReturn += "</url>\n";

	sReturn += "<description>";
	sReturn += StringUtil::EncodeToXmlCopy(pPage->description);
	sReturn += "</description>\n";

	sReturn += "</page>\n";

	return sReturn;
}

void XMLPrinter::generateKeywordXML(Occurrence* pOccurrence, void* pData){
	string* pReturn = (string*)pData;
	pReturn->append("<word>\n");

	pReturn->append("<value>");
	pReturn->append(pOccurrence->word);
	pReturn->append("</value>\n");

	pOccurrence->recurse(generateOccurrenceXML, pData);

	pReturn->append("</word>\n");
}

void XMLPrinter::generateOccurrenceXML(Instance* pInstance, void* pData){
	string* pReturn = (string*)pData;
	pReturn->append("<occurrence>\n");

	pReturn->append("<url>");
	pReturn->append(pInstance->url);
	pReturn->append("</url>\n");

	pReturn->append("<count>");
	std::stringstream ss;
	ss << pInstance->count;
	pReturn->append(ss.str());
	pReturn->append("</count>\n");

	pReturn->append("</occurrence>\n");
}
