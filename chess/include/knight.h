#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "knight.h"

class Knight : public Piece {
	public:
		/*
		 * Calls the super constructor.
		 * 
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		Knight(int x, int y, bool bWhite) : Piece(x, y, bWhite) {}

		/*
		 * Overriddes Piece's virtual method.
		 * 
		 * A move is valid if:
		 * - the move is an 'L' shape AND
		 * - no friendly piece occupies the new square
		 * 
		 * 'L' shape means:
		 * - 2 squares in the x direction and ane square in the y OR
		 * - 1 square in the y direction and one square in the x
		 * 
		 * If board is not set, then this method does the checks
		 * without checking to see if the resulting square is occupied
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
