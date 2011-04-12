#include "game.h"

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

Game::Game(int i) {
	this->bWhiteTurn = true;

	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			board[x][y] = NULL;
		}
	}
}

Game::Game(string savedGame) {
}

Game::~Game() {
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			if(board[x][y]){
				delete board[x][y];
				board[x][y] = NULL;
			}
		}
	}

	if (blackPieces.size()) {
		Piece* pPiece = blackPieces.top();
		while (pPiece != NULL) {
			delete pPiece;
			blackPieces.pop();

			pPiece = blackPieces.top();
		}
	}

	if (whitePieces.size()) {
		Piece* pPiece = whitePieces.top();
		while (pPiece != NULL) {
			delete pPiece;
			whitePieces.pop();

			pPiece = whitePieces.top();
		}
	}
}

Board* Game::getBoard() {
	return &this->board;
}

History* Game::getMoveHistory(){
	return &this->moveHistory;
}

bool Game::isWhiteTurn() {
	return this->bWhiteTurn;
}

void Game::changeSides() {
	this->bWhiteTurn = !this->bWhiteTurn;
}

void Game::move(Move tMove) {
	this->moveHistory.push(tMove);

	Piece* pPiece = this->board[tMove.getStartX()][tMove.getStartY()];
	this->board[tMove.getStartX()][tMove.getStartY()] = NULL;

	Piece* pCapturedPiece = this->board[tMove.getEndX()][tMove.getEndY()];
	if (pCapturedPiece) {
		if (pCapturedPiece->isWhite()) {
			this->whitePieces.push(pCapturedPiece);
		}
	}

	pPiece->move(tMove.getEndX(), tMove.getEndY());

	this->board[tMove.getEndX()][tMove.getEndY()] = pPiece;
}

Move Game::undoMove() {
	Move tMove = this->moveHistory.pop();

	Piece* pPiece = this->board[tMove.getEndX()][tMove.getEndY()];

	Piece* pCapturedPiece = NULL;
	if (tMove.getCapturedPiece() != P_NAN) {
		if (pPiece->isWhite()) {
			pCapturedPiece = blackPieces.top();
			blackPieces.pop();
		} else {
			pCapturedPiece = whitePieces.top();
			whitePieces.pop();
		}
	}
	this->board[tMove.getEndX()][tMove.getEndY()] = pCapturedPiece;

	this->board[tMove.getStartX()][tMove.getStartY()] = pPiece;

	pPiece->move(tMove.getStartX(), tMove.getStartY());

	return tMove;
}

bool Game::canUndo() {
	return !this->moveHistory.isEmpty();
}

bool Game::kingIsInCheck(bool bWhite) {
	PieceEnum tPiece = bWhite ? P_W_KING : P_B_KING;

	Piece* pKing = this->findPiece(tPiece);

	if (kingInCheckHorizontal(pKing) ||
		kingInCheckVertical(pKing) ||
		kingInCheckDiagonal(pKing) ||
		kingInCheckKnight(pKing) ){
		return true;
	}

	return false;
}

Piece* Game::findPiece(PieceEnum tEnum) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			Piece* pPiece = this->board[x][y];
			if (pPiece && pPiece->getType() == tEnum) {
				return pPiece;
			}
		}
	}
	return NULL;
}

bool Game::kingInCheckKnight(Piece* pKing) {
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
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 1;
	iY = y + 2;
	if (iX < 8 && iY < 8) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 2;
	iY = y - 1;
	if (iX < 8 && iY >= 0) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 2;
	iY = y + 1;
	if (iX >= 0 && iY < 8) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x + 1;
	iY = y - 2;
	if (iX < 8 && iY >= 0) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 1;
	iY = y + 2;
	if (iX >= 0 && iY < 8) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 2;
	iY = y - 1;
	if (iX >= 0 && iY >= 0) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	iX = x - 1;
	iY = y - 2;
	if (iX >= 0 && iY >= 0) {
		pPiece = this->board[iX][iY];
		if (pPiece && canCheckKnight(pPiece, bWhite)){
			return true;
		}
	}

	return false;
}

bool Game::kingInCheckDiagonal(Piece* pKing) {
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
	for(iX = x + 1, iY = y + 1; iX < 8 && iY < 8 && !bFriendly; iX++, iY++) {
		pPiece = this->board[iX][iY];
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
	for(iX = x - 1, iY = y + 1; iX >= 0 && iY < 8 && !bFriendly; iX--, iY++){
		pPiece = this->board[iX][iY];
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
	for(iX = x - 1, iY = y - 1; iX >= 0 && iY >= 0 && !bFriendly; iX--, iY--){
		pPiece = this->board[iX][iY];
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
	for(iX = x + 1, iY = y - 1; iX < 8 && iY >= 0 && !bFriendly; iX++, iY--){
		pPiece = this->board[iX][iY];
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

bool Game::kingInCheckVertical(Piece* pKing) {
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
	for(iY = y + 1; iY < 8 && !bFriendly; iY++){
		pPiece = this->board[x][iY];
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
	for(iY = y - 1; iY >= 0 && !bFriendly; iY--){
		pPiece = this->board[x][iY];
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

bool Game::kingInCheckHorizontal(Piece* pKing){
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
	for(iX = x + 1; iX < 8 && !bFriendly; iX++){
		pPiece = this->board[iX][y];
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
	for(iX = x - 1; iX >= 0 && !bFriendly; iX--){
		pPiece = this->board[iX][y];
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
