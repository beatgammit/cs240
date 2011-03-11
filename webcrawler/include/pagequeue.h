#ifndef __PAGEQUEUE_H__
#define __PAGEQUEUE_H__

#include "linkedlist.h"
#include "url.h"

using namespace std;

class PageQueue : public LinkedList {
	public:
		/*
		 * Pops the next item on the queue.
		 *
		 * @return A pointer to the next URL in the Queue.
		 */
		string pop();

		/*
		 * Push an item onto the queue.
		 *
		 * @param pURL- The URL to push onto the queue
		 */
		void push(string tURL);

		bool contains(string tURL);

		void Remove(LLNode* n);

		~PageQueue();
};
#endif
