#include "chesscontroller.h"

ImageName ChessController::mineToTheirs(PieceEnum tEnum) {
	ImageName tImage;

	switch (tEnum) {
		case P_W_BISHOP:{
			tImage = W_BISHOP;
			break;
		}
		case P_W_KING:{
			tImage = W_KING;
			break;
		}
		case P_W_KNIGHT:{
			tImage = W_KNIGHT;
			break;
		}
		case P_W_PAWN:{
			tImage = W_PAWN;
			break;
		}
		case P_W_QUEEN:{
			tImage = W_QUEEN;
			break;
		}
		case P_W_ROOK:{
			tImage = W_ROOK;
			break;
		}
		case P_B_BISHOP:{
			tImage = B_BISHOP;
			break;
		}
		case P_B_KING:{
			tImage = B_KING;
			break;
		}
		case P_B_KNIGHT:{
			tImage = B_KNIGHT;
			break;
		}
		case P_B_PAWN:{
			tImage = B_PAWN;
			break;
		}
		case P_B_QUEEN:{
			tImage = B_QUEEN;
			break;
		}
		case P_B_ROOK:{
			tImage = B_ROOK;
			break;
		}
	}

	return tImage;
}

ChessController::ChessController(int argc, char** argv){
}

void ChessController::on_CellSelected(int row, int col, int button) {
	Board* pBoard = this->game.getBoard();
	if (this->validMoves.size()) {
		while(validMoves.size()) {
			Move tMove = validMoves.front();
			validMoves.pop_front();

			this->pView->UnHighlightSquare(tMove.getEndY(), tMove.getEndX());

			if (tMove.getEndY() == row && tMove.getEndX() == col) {
				Piece* pPiece = (*pBoard)[tMove.getStartX()][tMove.getStartY()];
				game.move(tMove);

				this->pView->ClearPiece(tMove.getStartY(), tMove.getStartX());
				this->placePiece(pPiece);

				this->game.changeSides();
			}
		}
	} else if ((*pBoard)[col][row]) {
		this->selectPiece((*pBoard)[col][row]);
	}
}

void ChessController::on_DragStart(int row,int col) {
}

bool ChessController::on_DragEnd(int row,int col) {
}

void ChessController::on_NewGame() {
}

void ChessController::on_SaveGame() {
	if(this->currentGame == ""){
		this->currentGame = this->pView->SelectSaveFile();
	}

	IO::saveGame(this->currentGame, &this->game);
}

void ChessController::on_SaveGameAs() {
	IO::saveGame(this->pView->SelectSaveFile(), &this->game);
}

void ChessController::on_LoadGame() {
	IO::loadGame(this->pView->SelectLoadFile(), &this->game);

	Board* pBoard = this->game.getBoard();

	for (int x = 0; x < 8; x++){
		for (int y = 0; y < 8; y++){
			if ((*pBoard)[x][y]) {
				placePiece((*pBoard)[x][y]);
			}
		}
	}
}

void ChessController::on_UndoMove() {
	if (!game.canUndo()) {
		return;
	}

	Move tMove = game.undoMove();

	ImageName tPiece = ChessController::mineToTheirs(tMove.getPiece());
	PieceEnum tCaptured = tMove.getCapturedPiece();

	this->pView->ClearPiece(tMove.getEndY(), tMove.getEndX());
	this->pView->ClearPiece(3, 4);
	this->pView->PlacePiece(tMove.getStartY(), tMove.getStartX(), tPiece);

	if (tCaptured != P_NAN) {
		tPiece = ChessController::mineToTheirs(tCaptured);
		this->pView->PlacePiece(tMove.getEndY(), tMove.getEndX(), tPiece);
	}

	this->game.changeSides();
}

void ChessController::on_QuitGame() {
}

void ChessController::on_TimerEvent() {
}

void ChessController::SetView(IChessView* view) {
	this->pView = view;
}

void ChessController::placePiece(Piece* pPiece) {
	ImageName tImage = ChessController::mineToTheirs(pPiece->getType());

	this->pView->PlacePiece(pPiece->getY(), pPiece->getX(), tImage);
}

void ChessController::selectPiece(Piece* pPiece) {
	if (pPiece->isWhite() == this->game.isWhiteTurn()) {
		list<Move> moves = pPiece->getValidMoves(this->game.getBoard());

		list<Move>::iterator iter = moves.begin();
		while(iter != moves.end()) {
			this->game.move(*iter);
			if (!this->game.kingIsInCheck(pPiece->isWhite())) {
				validMoves.push_back(*iter);
				this->pView->HighlightSquare(iter->getEndY(), iter->getEndX(), BLUE_SQUARE);
			}
			this->game.undoMove();

			iter++;
		}
	}
}
