#ifndef __HTMLPARSER_H__
#define __HTMLPARSER_H__

#include "string"
#include "url.h"
#include "bst.h"
#include "keywordindex.h"
#include "pagequeue.h"
#include "pagesparsed.h"
#include "page.h"

/*
 * Parses HTML by adding links to a passed-in page queue.
 * Only a single page is handled at a time.
 *
 * This class can optionally handle downloading an HTML file from a URL
 * and handles both local files and files located at an internet address.
 *
 * Only HTML files are processed.  If a file is not valid HTML, no changes
 * will be made to the parameters passed into the parse method.
 */
class HTMLParser{
	public:
		/*
		 * Downloads the file and sets the data to a member variable.\
		 *
		 * @param tURL- The URL to parse
		 */
		HTMLParser(string& tURL);

		/*
		 * Will parse the page and returns the Page object tha was created
		 * if the parse was successful.
		 * In parsing a page, links are added to the PageQueue and keywords
		 * are added to the KeywordIndex.
		 *
		 * This method uses the HTMLTokenizer given in the CS240Utils package.
		 *
		 * A parse could fail if the page is not actually HTML.  If the parse
		 * fails, the return object will be NULL, otherwise the memory will
		 * have to be deallocated.
		 *
		 * @param pQueue- Queue of pages. Links are added to this queue.
		 * @param pIndex- KeywordIndex that keywords get added to
		 * @param pStopWords- Words to ignore when indexing the page
		 * @param iStopWords- Number of stor words
		 *
		 * @return A Page object with information pulled from this URL or NULL
		 */
		Page* parse(PageQueue* pQueue, PagesParsed* pPages, KeywordIndex* pIndex, string* pStopWords, int iStopWords);

	private:
		/*
		 * Downloads the page using the member variable.
		 *
		 * This method uses the URLInputStream given in the CS240Utils package.
		 *
		 * @return The contents of the file at the URL
		 */
		string downloadURL();

		/*
		 * Parses text into keywords and adds them to the keyword index.
		 *
		 * @param text- The text to be indexed
		 * @param pIndex- The keyword index to add keywords to
		 * @param pStopWords- the words to ignore when processing text
		 */
		void parseText(string text, KeywordIndex* pIndex, BST* pStopWords);

		/*
		 * Checks to see if the link is in scopo, and if so, adds it to the Queue if it isn't in the pages parsed
		 *
		 * A page is in scope if:
		 *   - the domains & starting path are the same
		 *   - the resulting url from a resolve follows the first point
		 *   - the extension is one of these: html, htm, shtml, cgi, jsp, asp, aspx, php, pl, cfm
		 *
		 * @param tURL- The URL to compare to the current page's URL
		 * @return True if the url is in scope, false otherwise.
		 */
		bool addLink(std::string tURL, PageQueue* pQueue, PagesParsed* pParsed);

		/*
		 * Determines whether a link is in scope.
		 * A page is in scope if the domains are the same.
		 *
		 * @param tURL- The URL to compare to the current page's URL
		 * @return True if the url is in scope, false otherwise.
		 */
		bool isInScope(string tURL);

		/* URL of the page to parse */
		string tUrl;
};
#endif
