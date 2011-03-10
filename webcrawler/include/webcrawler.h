#ifndef __WEBCRAWLER_H__
#define __WEBCRAWLER_H__

#include "string"
#include "keywordindex.h"
#include "pagequeue.h"
#include "pagesparsed.h"
#include "bst.h"
#include "url.h"

using namespace std;

/*
 * WebCrawler drives the application.
 *
 * Pages are parsed in the crawl method according to the spec.
 * Words found in the stop words data structure are ignored,
 * and all others are stored with a page count.
 */
class WebCrawler{
	public:
		/*
		 * Default constructor. This initializes the member variables.
		 */
		WebCrawler();

		/*
		 * Loads the stop words from the given file
		 *
		 * @param pFilePath- The path to a file containing the stop words
		 */
		void loadStopWords(char* pFilePath);

		/*
		 * Main function of this class.  This starts the indexing process.
		 *
		 * @param pStartURL- the URL to start on
		 */
		void crawl(string sURL);

		/*
		 * Turns the keyword index generated in the crawl method into XML.
		 * Should be called after crawl has been finished.
		 *
		 * @return XML representing a page index
		 */
		string toXML();

	private:
		/* Contains keywords that should be ignored (e.g. of, it, an...) */
		string* pStopWords;

		/* The number of stopwords */
		int iStopWords;

		/* Queue of pages yet te be processed */
		PageQueue pageQueue;

		/* Set of pages that have been processed */
		PagesParsed pagesParsed;

		/* Set of all of the keywords that have been indexed */
		KeywordIndex* pKeyIndex;

		string startURL;
};
#endif
