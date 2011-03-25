#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"

class Pawn : public Piece {
	public:
		/*
		 * Calls the super constructor.
		 * 
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		Pawn(int x, int y, bool bWhite) : Piece(x, y, bWhite) {}

		/*
		 * Overriddes Piece's virtual method.
		 * 
		 * A move is valid if:
		 * - the move is one square up & the square is unoccupied
		 * - the piece is two moves up, and neither square is oppupied
		 * - the move is next to the next square up and the square is occupied
		 * 
		 * If board is not set, then this method only does the first two checks
		 * without checking to see if the square is occupied
		 * 
		 * @param newX- the new x position
		 * @param newY- the new y position
		 * @param pBoard- if defined, the game board
		 * @return true if the move is valid, false if not
		 */
		bool isValidMove(int newK, int newY, Board* pBoard = NULL);

		/*
		 * Runs the test driver and outputs any errors to the output stream.
		 * 
		 * @param os- the output stream to output errors to
		 * @return True if all tests passed successfully, false otherwise
		 */
		bool test(ostream & os);
};

#endif
