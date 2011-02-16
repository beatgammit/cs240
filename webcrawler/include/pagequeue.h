#ifndef __PAGEQUEUE_H__
#define __PAGEQUEUE_H__

#include "linkedlist.h"
#include "url.h"

class PageQueue : public LinkedList {
	public:
		/*
		 * Pops the next item on the queue.
		 * 
		 * @return A pointer to the next URL in the Queue.
		 */
		URL* pop();

		/*
		 * Push an item onto the queue.
		 * 
		 * @param pURL- The URL to push onto the queue
		 */
		void push(URL* pURL);

		/*
		 * Checks to see if the queue is empty.
		 * 
		 * @return true if the queue is empty, false otherwise.
		 */
		bool empty();
}
#endif
