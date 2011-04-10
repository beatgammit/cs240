#include "chesscontroller.h"

ChessController::ChessController(int argc, char** argv){
}

void ChessController::on_CellSelected(int row, int col, int button) {
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

	if(!IO::saveGame(this->currentGame, &this->game)) {
		cout << "Error, Save failed..." << endl;
	}
}

void ChessController::on_SaveGameAs() {
	if(!IO::saveGame(this->pView->SelectSaveFile(), &this->game)) {
		cout << "Error, SaveAs failed..." << endl;
	}
}

void ChessController::on_LoadGame() {
	if(!IO::loadGame(this->pView->SelectLoadFile(), &this->game)) {
		cout << "Error, Load failed" << endl;
	}
}

void ChessController::on_UndoMove() {
}

void ChessController::on_QuitGame() {
}

void ChessController::on_TimerEvent() {
}

void ChessController::SetView(IChessView* view) {
	cout << "Hi" << endl;
	this->pView = view;
}
