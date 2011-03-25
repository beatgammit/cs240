#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"

class Rook : Piece {
	public:
		/*
		 * Calls the super constructor.
		 * 
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		Rook(int x, int y, bool bWhite) : Piece(x, y, bWhite) {}

		/*
		 * Overriddes Piece's virtual method.
		 * 
		 * A move is valid if:
		 * - the move is in the x direction & there are no pieces in the path
		 * - the move is in the y direction & there are no pieces in the path
		 * - the destination is not occupied by a friendly piece
		 * 
		 * If board is not set, then this method does the checks
		 * without checking to see if the path is obstructed
		 * 
		 * @param newX- the new x position
		 * @param newY- the new y position
		 * @param pBoard- if defined, the game board
		 * @return true if the move is valid, false if not
		 */
		bool isValidMove(int newX, int newY, Board* pBoard = NULL);

		/*
		 * Runs the test driver and outputs any errors to the output stream.
		 * 
		 * @param os- the output stream to output errors to
		 * @return True if all tests passed successfully, false otherwise
		 */
		bool test(ostream & os);
};

#endif
