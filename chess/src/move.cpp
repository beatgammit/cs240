#include "move.h"

Move::Move(int startX, int startY, int endX, int endY, PieceEnum piece, PieceEnum capturedPiece){
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;

	this->piece = piece;
	this->capturedPiece = capturedPiece;
}

bool Move::isWhite() {
	switch (this->piece) {
		case P_B_BISHOP:
		case P_B_KING:
		case P_B_KNIGHT:
		case P_B_PAWN:
		case P_B_QUEEN:
		case P_B_ROOK:{
			return false;
		}

		case P_W_BISHOP:
		case P_W_KING:
		case P_W_KNIGHT:
		case P_W_PAWN:
		case P_W_QUEEN:
		case P_W_ROOK:{
			return true;
		}

		default:{
			return false;
		}
	}
}
