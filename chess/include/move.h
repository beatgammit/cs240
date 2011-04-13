#ifndef __MOVE_H__
#define __MOVE_H__

enum PieceEnum {
	P_NAN,
	P_W_PAWN,
	P_W_ROOK,
	P_W_KNIGHT,
	P_W_BISHOP,
	P_W_QUEEN,
	P_W_KING,
	P_B_PAWN,
	P_B_ROOK,
	P_B_KNIGHT,
	P_B_BISHOP,
	P_B_QUEEN,
	P_B_KING
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
		Move(int startX, int startY, int endX, int endY, PieceEnum piece, PieceEnum capturedPiece = P_NAN);

		/*
		 * Gets the starting x position.
		 *
		 * @return the starting x position
		 */
		int getStartX() {
			return this->startX;
		}

		/*
		 * Gets the starting y position.
		 *
		 * @return the starting y position
		 */
		int getStartY() {
			return this->startY;
		}

		/*
		 * Gets the ending x position.
		 *
		 * @return the ending x position
		 */
		int getEndX() {
			return this->endX;
		}

		/*
		 * Gets the endning y position.
		 *
		 * @return the ending y position
		 */
		int getEndY(){
			return this->endY;
		}

		/*
		 * Gets the piece that did the moving.
		 *
		 * @return the piece that did the enum
		 */
		PieceEnum getPiece() {return this->piece;}

		bool isWhite();

		/*
		 * Gets the captured piece, if any.
		 *
		 * @return the captured piece, if any, or NAN
		 */
		PieceEnum getCapturedPiece() {return this->capturedPiece;}

		bool isHorizontal() {
			return (this->startY == this->endY && this->startX != this->endX);
		}

		bool isVertical() {
			return (this->startX == this->endX && this->startY != this->endY);
		}

		bool isDiagonal() {
			int xDiff = this->endX - this->startX;
			int yDiff = this->endY - this->startY;

			// take the product to remove sign
			return ((xDiff * xDiff) == (yDiff * yDiff));
		}

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
