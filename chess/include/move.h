#ifndef __MOVE_H__
#define __MOVE_H__

enum PieceEnum = {
	NAN,
	W_PAWN,
	W_ROOK,
	W_KNIGHT,
	W_BISHOP,
	W_QUEEN,
	W_KING,
	B_PAWN,
	B_ROOK,
	B_KNIGHT,
	B_BISHOP,
	B_QUEEN,
	B_KING
};

class Move {
	public:
		/*
		 * Constructor.
		 * 
		 * @param startX- starting x position
		 * @param startY- starting y position
		 * @param endX- ending x position
		 * @param endY- ending y position
		 * @param piece- the piece doing the moving
		 * @param capturedPiece- captured piece if any, NAN if none
		 */
		Move(int startX, int startY, int endX, int endY, PieceEnum piece, PieceEnum capturedPiece = NAN);

		/*
		 * Gets the starting x position.
		 * 
		 * @return the starting x position
		 */
		int getStartX();

		/*
		 * Gets the starting y position.
		 * 
		 * @return the starting y position
		 */
		int getStartY();

		/*
		 * Gets the ending x position.
		 * 
		 * @return the ending x position
		 */
		int getEndX();

		/*
		 * Gets the endning y position.
		 * 
		 * @return the ending y position
		 */
		int getEndY();

		/*
		 * Gets the piece that did the moving.
		 * 
		 * @return the piece that did the enum
		 */
		PieceEnum getPiece();

		/*
		 * Gets the captured piece, if any.
		 * 
		 * @return the captured piece, if any, or NAN
		 */
		PieceEnum getCapturedPiece();

	private:
		/* Starting x position */
		int startX;

		/* Starting y position */
		int startY;

		/* Ending x position */
		int endX;

		/* Ending y position */
		int endY;

		/* Piece that did the moving */
		PieceEnum piece;

		/* Captured piece, if any */
		PieceEnum capturedPiece;
};

#endif
