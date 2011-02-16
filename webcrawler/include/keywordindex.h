#ifndef __KEYWORDINDEX_H__
#define __KEYWERDINDEK_H__

#include "string"
#include "bst.h"

class KeywordIndex {
	public:
		/*
		 * Default constructor. Initializes member variables.
		 */
		KeywordIndex();

		/*
		 * Either creates a new entry in the index or increments the count
		 * if it already exists.
		 * 
		 * @param word- The keyword to add to the index
		 * @param url- the URL where this keyword was found
		 */
		void put(string word, string url);

		/*
		 * Gets the set of occurrences for the given keyword.
		 * 
		 * @param word- The keyword to search for
		 * @return BST that represents the occurrence map or NULL
		 */
		BST* get(string word);

		/*
		 * Walks the tree recursively calling the function with the
		 * item data as the first parameter and the passed in data as the
		 * second parameter.
		 * 
		 * @param function- The function to call at each node
		 * @param pData- the data to include in the function call
		 */
		void recurse(void* function(), void* pData = NULL);

	private:
		/* The keyword index */
		BST* pIndex;
}
#endif
