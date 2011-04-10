#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include <list>

#include "move.h"

using namespace std;

class Piece {
	public:
		/*
		 * Contructor. This should only be called by subclasses.
		 * The x and y positions are only used in determining legality of moves.
		 *
		 * @param x- x position on board
		 * @param y- y position on board
		 * @param bWhite- true if white, false if black
		 */
		Piece(int x, int y, bool bWhite) : x(x), y(y), bWhite(bWhite) {}

		/*
		 * Moves the piece to the location specified.
		 * A call to isValidMove should have already been made.
		 *
		 * The board is not updated and should be handled separately.
		 */
		void move(int newX, int newY){
			x = newX;
			y = newY;
		}

		/*
		 * Gets the x coordinate.
		 *
		 * @return The x coordinate of this piece
		 */
		int getX(){return x;}

		/*
		 * Gets the y coordinate.
		 *
		 * @return The y coordinate of this piece
		 */
		int getY(){return x;}

		/*
		 * Gets whether this piece is white.
		 *
		 * @return True if this is white, false if black
		 */
		bool isWhite(){return bWhite;}

		/*
		 * Gets a list of valid moves.  A move is valid if:
		 * - the piece could get to the position legally on an empty board
		 * - if pBoard is not null, the are no pieces restricting movement
		 * - if the piece is a king, the move cannot directly result in capture
		 *
		 * @param pBoard- if defined, the game board
		 * @return a list of valid moves
		 */
		virtual list<Move> getValidMoves(Piece** pBoard = NULL) {}

		/*
		 * Runs a test driver to test isValidMove.
		 *
		 * @param os- the output stream to output all failed tests to
		 * @return True if all tests passed, false if not
		 */
		virtual bool test(ostream & os) {}

	private:
		int x;
		int y;
		bool bWhite;
};

#endif
