#include "pawn.h"

list<Move> Pawn::getValidMoves(TBoard* pBoard) {
	list<Move> possibleMoves = this->getPossibleMoves(pBoard);

	return possibleMoves;
}

list<Move> Pawn::getPossibleMoves(TBoard* pBoard) {
	list<Move> possibleMoves;
	int iY;
	int iY2;

	if (this->isWhite()) {
		iY = this->getY() - 1;

		iY2 = this->getY() == 6 ? iY - 1 : 0;
	} else {
		iY = this->getY() + 1;

		iY2 = this->getY() == 1 ? iY + 1 : 0;
	}

	// single forward move
	Piece* pPiece = (*pBoard)[this->getX()][iY];
	if (!pPiece) {
		Move tMove = Move(this->getX(), this->getY(), this->getX(), iY, this->getType());
		possibleMoves.push_back(tMove);

		if (iY2) {
			pPiece = (*pBoard)[this->getX()][iY2];
			if (!pPiece) {
				tMove = Move(this->getX(), this->getY(), this->getX(), iY2, this->getType());
				possibleMoves.push_back(tMove);
			}
		}
	}

	if (this->getX() < 7) {
		// capturing moves
		pPiece = (*pBoard)[this->getX() + 1][iY];
		if (pPiece && pPiece->isWhite() != this->isWhite()) {
			Move tMove = Move(this->getX(), this->getY(), this->getX() + 1, iY, this->getType(), pPiece->getType());
			possibleMoves.push_back(tMove);
		}
	}

	if (this->getX() > 1) {
		pPiece = (*pBoard)[this->getX() - 1][iY];
		if (pPiece && pPiece->isWhite() != this->isWhite()) {
			Move tMove = Move(this->getX(), this->getY(), this->getX() - 1, iY, this->getType(), pPiece->getType());
			possibleMoves.push_back(tMove);
		}
	}

	return possibleMoves;
}

bool Pawn::test(ostream & os) {
}
