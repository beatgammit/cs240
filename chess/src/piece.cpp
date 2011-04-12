#include "piece.h"

/*
 * Checks to see whether a piece can check horizontally...
bool canCheckHorizontal(Piece* pPiece, bool bWhite) {
	switch(pPiece->getType()){
		case P_W_QUEEN:
		case P_B_QUEEN:
		case P_W_ROOK:
		case P_B_ROOK:{
			if(pPiece->isWhite() != bWhite){
				return true;
			}else{
				return false;
			}
		}
		default:{
			break;
		}
	}
	return false;
}

bool canCheckVertical(Piece* pPiece, bool bWhite) {
	switch(pPiece->getType()){
		case P_W_QUEEN:
		case P_B_QUEEN:
		case P_W_ROOK:
		case P_B_ROOK:{
			if (pPiece->isWhite() != bWhite) {
				return true;
			}else {
				return false;
			}
		}
		default:{
			break;
		}
	}
	return false;
}

bool canCheckDiagonal(Piece* pPiece, bool bWhite) {
	switch(pPiece->getType()){
		case P_W_QUEEN:
		case P_B_QUEEN:
		case P_W_BISHOP:
		case P_B_BISHOP:{
			if(pPiece->isWhite() != bWhite){
				return true;
			}else{
				return false;
			}
		}
		default:{
			break;
		}
	}
	return false;
}

bool canCheckKnight(Piece* pPiece, bool bWhite) {
	switch(pPiece->getType()){
		case P_W_KNIGHT:
		case P_B_KNIGHT:{
			if(pPiece->isWhite() != bWhite){
				return true;
			}else{
				return false;
			}
		}
		default:{
			break;
		}
	}
	return false;
}
 */

bool isKing(Piece* pPiece, bool bWhite) {
	if (pPiece->getType() == P_W_KING && bWhite ||
		pPiece->getType() == P_B_KING && !bWhite){
		return true;
	}
	return false;
}

/*
bool Piece::affectsKingHoriz(TBoard* pBoard) {
	bool enemyFound = false;
	bool kingFound = false;

	Piece* pPiece = NULL;

	int iX;
	// check for threats to the right
	for(iX = this->getX() + 1; iX < 8; iX++){
		pPiece = (*pBoard)[iX][this->getY()];
		if (pPiece) {
			if (canCheckHorizontal(pPiece, this->isWhite())) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	if (!kingFound && !enemyFound){
		return false;
	}

	// check for threats to the right
	for(iX = this->getX() - 1; iX >= 0; iX--){
		pPiece = (*pBoard)[iX][this->getY()];
		if (pPiece) {
			if (canCheckHorizontal(pPiece, this->isWhite())) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	return (kingFound && enemyFound);
}

bool Piece::affectsKingVert(TBoard* pBoard) {
	bool enemyFound = false;
	bool kingFound = false;

	Piece* pPiece = NULL;

	int iY;
	// check for threats to the right
	for(iY = this->getY() + 1; iY < 8; iY++){
		pPiece = (*pBoard)[this->getX()][iY];
		if (pPiece) {
			if (canCheckVertical(pPiece, this->isWhite())) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	if (!kingFound && !enemyFound){
		return false;
	}

	// check for threats to the right
	for(iY = this->getY() - 1; iY >= 0; iY--){
		pPiece = (*pBoard)[this->getX()][iY];
		if (pPiece) {
			if (canCheckHorizontal(pPiece, this->isWhite())) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	return (kingFound && enemyFound);
}

bool Piece::affectsKingDiagonal(TBoard* pBoard) {
	// temporary x and y values
	int iX = 0;
	int iY = 0;

	bool enemyFound = false;
	bool kingFound = false;

	// temporary piece
	Piece* pPiece = NULL;

	// check for threats to the upper-right
	for(iX = this->getX() + 1, iY = this->getY() + 1; iX < 8 && iY < 8; iX++, iY++) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	if (kingFound || enemyFound) {
		// check for threats to the lower left
		for(iX = this->getX() - 1, iY = this->getY() - 1; iX >= 0 && iY >= 0; iX--, iY--){
			pPiece = (*pBoard)[iX][iY];
			if (pPiece) {
				if (canCheckDiagonal(pPiece, bWhite)) {
					enemyFound = true;
				} else if (isKing(pPiece, this->isWhite())) {
					kingFound = true;
				}
				break;
			}
		}

		if (kingFound && enemyFound) {
			return true;
		}
	}

	kingFound = false;
	enemyFound = false;

	// check for threats to the upper left
	for(iX = this->getX() - 1, iY = this->getY() + 1; iX >= 0 && iY < 8; iX--, iY++){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				enemyFound = true;
			} else if (isKing(pPiece, this->isWhite())) {
				kingFound = true;
			}
			break;
		}
	}

	if (kingFound || enemyFound) {
		// check for threats to the lower right
		for(iX = this->getX() + 1, iY = this->getY() - 1; iX < 8 && iY >= 0; iX++, iY--){
			pPiece = (*pBoard)[iX][iY];
			if (pPiece) {
				if (canCheckDiagonal(pPiece, bWhite)) {
					enemyFound = true;
				} else if (isKing(pPiece, this->isWhite())) {
					kingFound = true;
				}
				break;
			}
		}
	}

	return (kingFound && enemyFound);
}


bool Piece::kingIsInCheck(TBoard* pBoard, Piece* pKing) {
	if (!pBoard || pKing) {
		return false;
	}

	if (kingInCheckHorizontal(pBoard, pKing) ||
		kingInCheckVertical(pBoard, pKing) ||
		kingInCheckDiagonal(pBoard, pKing) ||
		kingInCheckKnight(pBoard, pKing) ){
		return true;
	}

	return false;
}

bool Piece::kingInCheckKnight(TBoard* pBoard, Piece* pKing) {
	int x = pKing->getX();
	int y = pKing->getY();
	bool bWhite = pKing->isWhite();

	// temporary x and y values
	int iX = 0;
	int iY = 0;

	// temporary piece
	Piece* pPiece = NULL;

	iX = x + 2;
	iY = y + 1;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 1;
	iY = y + 2;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 2;
	iY = y - 1;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 2;
	iY = y + 1;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 1;
	iY = y - 2;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 1;
	iY = y + 2;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 2;
	iY = y - 1;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 1;
	iY = y - 2;
	if (iX < 8 && iY < 8) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	return false;
}

bool Piece::kingInCheckDiagonal(TBoard* pBoard, Piece* pKing) {
	int x = pKing->getX();
	int y = pKing->getY();
	bool bWhite = pKing->isWhite();

	// temporary x and y values
	int iX = 0;
	int iY = 0;

	// temporary piece
	Piece* pPiece = NULL;

	bool bFriendly;
	bFriendly = false;

	// check for threats to the upper-right
	for(iX = x + 1, iY = y + 1; x < 8 && y < 8 && !bFriendly; iX++, iY++) {
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	bFriendly = false;
	// check for threats to the upper left
	for(iX = x - 1, iY = y + 1; x >= 0 && y < 8 && !bFriendly; iX--, iY++){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	bFriendly = false;
	// check for threats to the lower left
	for(iX = x - 1, iY = y - 1; x >= 0 && y >= 0 && !bFriendly; iX--, iY--){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	bFriendly = false;
	// check for threats to the lower right
	for(iX = x + 1, iY = y - 1; x < 8 && y >= 8 && !bFriendly; iX++, iY--){
		pPiece = (*pBoard)[iX][iY];
		if (pPiece) {
			if (canCheckDiagonal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	return false;
}

bool Piece::kingInCheckVertical(TBoard* pBoard, Piece* pKing) {
	int x = pKing->getX();
	int y = pKing->getY();
	bool bWhite = pKing->isWhite();

	// temporary x and y values
	int iY = 0;

	// temporary piece
	Piece* pPiece = NULL;

	bool bFriendly;
	bFriendly = false;
	// check for threats to the right
	for(iY = y + 1; y < 8 && !bFriendly; iY++){
		pPiece = (*pBoard)[x][iY];
		if (pPiece) {
			if (canCheckVertical(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	bFriendly = false;
	// check for threats to the left
	for(iY = y - 1; y >= 0 && !bFriendly; iY--){
		pPiece = (*pBoard)[x][iY];
		if(pPiece){
			if (canCheckVertical(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}
	return false;
}

bool Piece::kingInCheckHorizontal(TBoard* pBoard, Piece* pKing){
	int x = pKing->getX();
	int y = pKing->getY();
	bool bWhite = pKing->isWhite();

	// temporary x and y values
	int iX = 0;

	// temporary piece
	Piece* pPiece = NULL;

	bool bFriendly;
	bFriendly = false;
	// check for threats to the right
	for(iX = x + 1; x < 8 && !bFriendly; iX++){
		pPiece = (*pBoard)[iX][y];
		if (pPiece) {
			if (canCheckHorizontal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}

	bFriendly = false;
	// check for threats to the left
	for(iX = x - 1; x >= 0 && !bFriendly; iX--){
		pPiece = (*pBoard)[iX][y];
		if(pPiece){
			if (canCheckHorizontal(pPiece, bWhite)) {
				return true;
			} else {
				bFriendly = true;
				break;
			}
		}
	}
	return false;
}
*/
