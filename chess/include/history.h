#ifndef __HISTORY_H__
#define __HISTORY_H__

#include <deque>
#include <iostream>

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

		void push(Move tMove);

		/*
		 * Calls push in Stack.
		 *
		 * @param tMove- the move to push on the history
		 */
		void push(int startX, int startY, int endX, int endY, PieceEnum tPiece, PieceEnum tCaptured = P_NAN);

		/*
		 * Calls pop in Stack.
		 *
		 * @return The previous Move
		 */
		Move pop();

		Move popBack();

		bool isEmpty();

		/*
		 * Clears the move history.
		 */
		void clear();

	private:
		deque<Move> moveHistory;
};

#endif
