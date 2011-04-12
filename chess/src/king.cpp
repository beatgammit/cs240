#include "king.h"

list<Move> King::getValidMoves(TBoard* pBoard) {
	return getPossibleMoves(pBoard);
}

list<Move> King::getPossibleMoves(TBoard* pBoard) {
	list<Move> possibleMoves;

	Piece* pPiece;
	for(int iX = this->getX() - 1; iX <= this->getX() + 1; iX++) {
		for(int iY = this->getY() - 1; iY <= this->getY() + 1; iY++) {
			if (iX >= 0 && iX < 8 && iY >= 0 && iY < 8) {
				pPiece = (*pBoard)[iX][iY];
				if (!pPiece) {
					Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
					possibleMoves.push_back(tMove);
				} else if (pPiece->isWhite() != this->isWhite()) {
					Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
					possibleMoves.push_back(tMove);
				}
			}
		}
	}

	return possibleMoves;
}

bool King::test(ostream & os) {
}
