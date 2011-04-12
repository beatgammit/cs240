#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <list>

#include "piece.h"

using namespace std;

class Bishop : public Piece {
	public:
		/*
		 * Calls the super constructor.
		 *
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		Bishop(int x, int y, bool bWhite) : Piece(x, y, bWhite) {}

		/*
		 * Overriddes Piece's virtual method.
		 *
		 * A move is valid if:
		 * - the move is diagonal & there are no pieces in the path
		 * - the resulting square is not occupied by a friendly piece
		 *
		 * If board is not set, then this method does the checks
		 * without checking to see if the path is obstructed
		 *
		 * @param pBoard- if defined, the game board
		 * @param pKing- king piece, defaults to NULL
		 * @return a list of valid moves
		 */
		virtual list<Move> getValidMoves(TBoard* pBoard = NULL);

		/*
		 * Runs the test driver and outputs any errors to the output stream.
		 *
		 * @param os- the output stream to output errors to
		 * @return True if all tests passed successfully, false otherwise
		 */
		virtual bool test(ostream & os);

		virtual PieceEnum getType() {return this->isWhite() ? P_W_BISHOP : P_B_BISHOP;}

	private:
		list<Move> getPossibleMoves(TBoard* pBoard);
};

#endif
