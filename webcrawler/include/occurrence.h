#ifndef __OCCURRENCE_H__
#define __OCCURRENCE_H__

#include "string"

#include "bst.h"

struct Instance{
	string url;
	unsigned int count;
};

class Occurrence : public BST {
	friend class BST;
	friend class BSTNode;
	public:
		Occurrence(std::string word){
			this->pRoot = NULL;
			this->word = word;
		}
		/*
		 * If there is no url in this set, add it with a count of 1.
		 *
		 * If the url is already in this set, increment the count.
		 */
		void put(string url);

		std::string getWord(){
			return word;
		}

		/*
		 * Walks the tree recursively calling the function with the
		 * item data as the first parameter and the passed in data as the
		 * second parameter.
		 *
		 * @param function- The function to call at each node
		 * @param pData- the data to include in the function call
		 */
		void recurse(void (*function)(Instance* data, void* pData), void* pData = NULL);

		string word;

	private:
		void recurse(BSTNode* pStart, void (*function)(Instance* data, void* pData), void* pData = NULL);

};
#endif
