#ifndef __KEYWORDINDEX_H__
#define __KEYWORDINDEX_H__

#include "string"

#include "bst.h"
#include "occurrence.h"

class KeywordIndex : public BST{
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
		Occurrence* get(string word);

		/*
		 * Walks the tree recursively calling the function with the
		 * item data as the first parameter and the passed in data as the
		 * second parameter.
		 *
		 * @param function- The function to call at each node
		 * @param pData- the data to include in the function call
		 */
		void recurse(void (*function)(Occurrence* pOccurrence, void* data), void* pData = NULL);

		void Clear(BSTNode* pStart);

		~KeywordIndex();

	private:
		void recurse(BSTNode* pNode, void (*function)(Occurrence* pOccurrence, void* data),
					void* pData = NULL);
};
#endif
