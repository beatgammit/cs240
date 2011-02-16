#ifndef __OCCURRENCE_H__
#define

#include "bst.h"
#include "string"

struct Instance{
	string url;
	unsigned int count;
};

class Occurrence : BST {
	public:
		/*
		 * If there is no url in this set, add it with a count of 1.
		 * 
		 * If the url is already in this set, increment the count.
		 */
		void put(string url);

		/*
		 * Walks the tree recursively calling the function with the
		 * item data as the first parameter and the passed in data as the
		 * second parameter.
		 * 
		 * @param function- The function to call at each node
		 * @param pData- the data to include in the function call
		 */
		 void recurse(void* function(), void* pData = NULL);
}
#endif
