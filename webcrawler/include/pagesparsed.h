#ifndef __PAGESPARSED_H__
#define __PAGESPARSED_H__

#include "string"

#include "page.h"
#include "url.h"
#include "linkedlist.h"


/*
 * Stores the pages that have already been parsed.
 * There could be a lot of these, but not so many to require a BST.
 */
class PagesParsed : public LinkedList {
	public:
		/*
		 * Convenience function to check if a page is in the tree.
		 *
		 * @param pURL The URL to check for
		 * @return true if the URL is in the tree, false if not
		 */
		bool pageProcessed(std::string tURL);

		/*
		 * Adds a page to the list.
		 *
		 * @param pPage- The page to add to the list
		 */
		void add(Page* pPage);

		void Remove(LLNode* pNode);

		void Clear();

		~PagesParsed();
};
#endif
