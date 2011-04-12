#include "knight.h"

list<Move> Knight::getValidMoves(TBoard* pBoard) {
	list<Move> validMoves;

	list<Move> possibleMoves = this->getPossibleMoves(pBoard);

	return possibleMoves;
}

list<Move> Knight::getPossibleMoves(TBoard* pBoard) {
	list<Move> possibleMoves;

	// temporary x and y values
	int iX = 0;
	int iY = 0;

	// temporary piece
	Piece* pPiece = NULL;

	iX = this->getX() + 2;
	iY = this->getY() + 1;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() + 1;
	iY = this->getY() + 2;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() + 2;
	iY = this->getY() - 1;
	if (iX < 8 && iY >= 0) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() - 2;
	iY = this->getY() + 1;
	if (iX >= 0 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() + 1;
	iY = this->getY() - 2;
	if (iX < 8 && iY >= 0) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() - 1;
	iY = this->getY() + 2;
	if (iX >= 0 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() - 2;
	iY = this->getY() - 1;
	if (iX >= 0 && iY >= 0) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	iX = this->getX() - 1;
	iY = this->getY() - 2;
	if (iX >= 0 && iY >= 0) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece){
			if (pPiece->isWhite() != this->isWhite()) {
				Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType(), pPiece->getType());
				possibleMoves.push_back(tMove);
			}
		} else {
			Move tMove = Move(this->getX(), this->getY(), iX, iY, this->getType());
			possibleMoves.push_back(tMove);
		}
	}

	return possibleMoves;
}

bool Knight::test(ostream & os) {
}
