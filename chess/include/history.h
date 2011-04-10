#ifndef __HISTORY_H__
#define __HISTORY_H__

#include <stack>

#include "move.h"

using namespace std;

class History {
	public:
		/*
		 * Default constructor. Initializes stack.
		 */
		History();

		/*
		 * Destructor. Cleans up its own mess.
		 */
		~History();

		/*
		 * Calls push in Stack.
		 *
		 * @param tMove- the move to push on the history
		 */
		void push(Move tMove);

		/*
		 * Calls pop in Stack.
		 *
		 * @return The previous Move
		 */
		Move pop();

		/*
		 * Clears the move history.
		 */
		void clear();

	private:
		stack<Move> moveHistory;
};

#endif
