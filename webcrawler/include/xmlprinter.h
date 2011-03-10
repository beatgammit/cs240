#ifndef __XML_PRINTER_H__
#define __XML_PRINTER_H__

#include "url.h"
#include "page.h"
#include "pagesparsed.h"
#include "bst.h"
#include "keywordindex.h"
#include "occurrence.h"

/*
 * Prints the results of the indexing process in XML according to the
 * specifications of the project.  This class would use a library for
 * creating XML documents if the project specifications allowed it.
 */
class XMLPrinter{
	public:
		/*
		 * Generates the XML.
		 *
		 * @return XML representation of the data
		 */
		static string generateXML(std::string startURL, PagesParsed* pPages, KeywordIndex* pIndex);
	private:
		/*
		 * Generates the page part of the XML.
		 *
		 * @param pPage The page to generate the XML for
		 * @return XML represeting data in this page
		 */
		static std::string generatePageXML(Page* pPage);

		/*
		 * Generates the XML for a keyword.
		 * This is static so it can be passed into other functions.
		 *
		 * @param keyword The keyword in question
		 * @param pOccurrenceMap- a map of all occurrences of this word
		 * @return XML representing the occurrences of this keyword
		 */
		static void generateKeywordXML(Occurrence* pOccurrence, void* pData);

		/*
		 * Generates the XML for an occurrence.
		 * This is static so it can be passed into other functions.a
		 * This function will be passed into Occurrence's recurse method
		 * within generateKeyvordXML.
		 *
		 * @param url The keyword in question
		 * @param pInstance- the instance in the occurrence map
		 * @return XML representing the occurrence at this url
		 */
		static void generateOccurrenceXML(Instance* pInstance, void* pData);
};
#endif
