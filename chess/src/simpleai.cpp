#include "simpleai.h"

Move SimpleAI::generateMove(TBoard* pBoard, Move* pOppMove) {
	for(int x = 0; x < 8; x++) {
		for(int y = 0; y < 8; y++) {
			Piece* pPiece = (*pBoard)[x][y];
			if (pPiece && pPiece->isWhite() == this->isWhite()) {
				//list<Move> legalMoves = pPiece->getValidMoves
			}
		}
	}
}
