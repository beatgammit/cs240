#ifndef __ROOK_H__
#define __ROOK_H__

#include <list>

#include "piece.h"

using namespace std;

class King : Piece {
	public:
		/*
		 * Calls the super constructor.
		 *
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		King(int x, int y, bool bWhite) : Piece(x, y, bWhite) {}

		/*
		 * Overriddes Piece's virtual method.
		 *
		 * A move is valid if:
		 * - the move is only one square away
		 * - the destination is not occupied by a friendly piece
		 * - the destination will not result in capture
		 *
		 * If board is not set, then this method does the checks
		 * without checking to see if the path is obstructed
		 *
		 * @param pBoard- if defined, the game board
		 * @return a list of valid moves
		 */
		virtual list<Move> getValidMoves(Piece** pBoard = NULL);

		/*
		 * Runs the test driver and outputs any errors to the output stream.
		 *
		 * @param os- the output stream to output errors to
		 * @return True if all tests passed successfully, false otherwise
		 */
		virtual bool test(ostream & os);
};

#endif
