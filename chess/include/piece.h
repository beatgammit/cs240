#ifndef __PIECE_H__
#define __PIECE_H__

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
		void move(int newX, int newY) : x(newX), y(newY) {}

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
		 * Checks to see if the move is legal.  The move is legal if:
		 * - the piece could get to the position legally on an empty board
		 * - if pBoard is not NULL, the are no pieces restricting movement
		 * - if the piece is a king, the move cannot directly result in capture
		 * 
		 * @param newX- the new x position
		 * @param newY- the new y position
		 * @param pBoard- if defined, the game board
		 * @return true if the move is valid, false if not
		 */
		virtual bool isValidMove(int newX, int newY, Board* pBoard = NULL);

		/*
		 * Runs a test driver to test isValidMove.
		 * 
		 * @param os- the output stream to output all failed tests to
		 * @return True if all tests passed, false if not
		 */
		virtual bool test(ostream & os);
	
	private:
		int x;
		int y;
		bool bWhite;
};

#endif
