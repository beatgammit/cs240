#ifndef __BOARD_H__
#define __BOARD_H__

/*
 * Represents a Chess board as a 2-dimensional array of Piece pointers.
 */
class Board {
	public:
		/*
		 * Default constructor. Initializes board.
		 */
		Board();

		/*
		 * Destructor. Frees board.
		 */
		~Board();

		/*
		 * Resets the board to factory settings.
		 * Arranges the pieces according to standard chess regulations.
		 */
		void reset();

		/*
		 * Gets the piece at a specific location.
		 *
		 * @param x- the x coordinate of a piece
		 * @param y- the y coordinate of a piece
		 */
		Piece* getPiece(int x, int y);

		/*
		 * Adds a piece to the board at the specified location.
		 * 
		 * @param pPiece- the piece to add
		 * @param x- the x coordinate to add the piece to
		 * @param y- the y coordinate to add the piece to
		 */
		void addPiece(Piece* pPiece, int x, int y);

		/*
		 * Removes a piece to the board at the specified location.
		 * 
		 * @param x- the x coordinate of the piece to remove
		 * @param y- the y coordinate to the piece to remove
		 * @return The piece that was removed
		 */
		Piece* removePiece(int x, int y);

		/*
		 * Calls remove then add.
		 *
		 * @param startX- the x coordinate of the piece to
		 * @param startY- the y coordinate of the piece to
		 * @param endX- the x coordinate to move the piece to
		 * @param endY- the y coordinate to move the piece to
		 * @return The piece that was moved
		 */
		Piece* movePiece(int startX, int startY, int endX, int endY);

		/*
		 * Returns true if there is a check on the board, false otherwise.
		 * 
		 * @return Whether there is a check on the board
		 */
		bool hasCheck();

		/*
		 * Returns true if there is a checkmate on the board, false otherwise.
		 * 
		 * @return Whether there is a checkmate on the board
		 */

		bool hasCheckMate();

		/*
		 * True if the current player has no more moves.
		 * 
		 * @return true if there is a stalemate, false otherwise
		 */
		bool isStaleMate();

		/*
		 * Uses the same logic as hasCheckMate.
		 * 
		 * @return True if white has won, false otherwise
		 */
		bool whiteWon();

		/*
		 * Uses the same logic as hasCheckMate.
		 * 
		 * @return True if black has won, false otherwise
		 */
		bool blackWon();

	private:
		/* 2-Dimensional array */
		Piece** board[][];
};

#endif
