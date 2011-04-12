#include "bishop.h"

list<Move> Bishop::getValidMoves(TBoard* pBoard) {
	list<Move> validMoves;

	list<Move> possibleMoves = this->getPossibleMoves(pBoard);

	return possibleMoves;
}

list<Move> Bishop::getPossibleMoves(TBoard* pBoard) {
	list<Move> possibleMoves;

	// temporary x and y values
	int iX = 0;
	int iY = 0;

	// temporary piece
	Piece* pPiece = NULL;

	// check for threats to the upper-right
	for(iX = this->getX() + 1, iY = this->getY() + 1; iX < 8 && iY < 8; iX++, iY++) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
			break;
		}
		Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
		possibleMoves.push_back(tMove);
	}

	// check for threats to the upper left
	for(iX = this->getX() - 1, iY = this->getY() + 1; iX >= 0 && iY < 8; iX--, iY++){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
			break;
		}
		Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
		possibleMoves.push_back(tMove);
	}

	// check for threats to the lower left
	for(iX = this->getX() - 1, iY = this->getY() - 1; iX >= 0 && iY >= 0; iX--, iY--){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
			break;
		}
		Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
		possibleMoves.push_back(tMove);
	}

	// check for threats to the lower right
	for(iX = this->getX() + 1, iY = this->getY() - 1; iX < 8 && iY >= 0; iX++, iY--){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
			break;
		}
		Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
		possibleMoves.push_back(tMove);
	}

	return possibleMoves;
}

bool Bishop::test(ostream & os) {
}
