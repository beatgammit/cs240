#include "move.h"

Move::Move(int startX, int startY, int endX, int endY, PieceEnum piece, PieceEnum capturedPiece){
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;

	this->piece = piece;
	this->capturedPiece = capturedPiece;
}
