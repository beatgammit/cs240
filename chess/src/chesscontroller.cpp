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
	this->selectedX = -1;
	this->selectedY = -1;

	if (argc == 2) {
		//this->game = Game(atoi(argv[1]));
	}

	bSaved = false;

	bIgnoreTimeout = true;
	//Chess::SetTimeoutMilliseconds(2000);
}

void ChessController::on_CellSelected(int row, int col, int button) {
	if (this->selectedX >= 0 && this->selectedY >= 0) {
		this->clearSelection(row, col);

/*		while (game.aiIsNext()) {
			this->makeMove(game.getAIMove());
		}*/
		/*
	} else if (this->game.canMove(col, row)) {
		this->validMoves = this->game.getLegalMoves(col, row);

		list<Move>::iterator iter = this->validMoves.begin();
		while(iter != validMoves.end()) {
			if (iter->getCapturedPiece() == P_NAN) {
				this->pView->HighlightSquare(iter->getEndY(), iter->getEndX(), BLUE_SQUARE);
			} else {
				this->pView->HighlightSquare(iter->getEndY(), iter->getEndX(), GREEN_SQUARE);
			}
			iter++;
		}

		selectedX = col;
		selectedY = row;

		this->pView->HighlightSquare(row, col, RED_SQUARE);*/
	}
}

void ChessController::on_DragStart(int row,int col) {/*
	bIgnoreTimeout = true;

	if (this->game.canMove(col, row)) {
		this->validMoves = this->game.getLegalMoves(col, row);

		list<Move>::iterator iter = this->validMoves.begin();
		while(iter != validMoves.end()) {
			if (iter->getCapturedPiece() == P_NAN) {
				this->pView->HighlightSquare(iter->getEndY(), iter->getEndX(), BLUE_SQUARE);
			} else {
				this->pView->HighlightSquare(iter->getEndY(), iter->getEndX(), GREEN_SQUARE);
			}
			iter++;
		}

		selectedX = col;
		selectedY = row;

		this->pView->HighlightSquare(row, col, RED_SQUARE);
	}*/
}

bool ChessController::on_DragEnd(int row,int col) {
	this->clearSelection(row, col);
	bIgnoreTimeout = false;
}

void ChessController::on_NewGame() {
	/*
	bIgnoreTimeout = true;

	this->pView->SetStatusBar("");
	this->currentGame = "";

	// clear everything
	this->clearSelection();
	this->clearBoard();
	this->game = Game();

	Board* pBoard = this->game.getBoard();

	// just loop through once... we can make it work
	for (int x = 0; x < 8; x++) {
		(*pBoard)[x][1] = new Pawn(x, 1, false);
		this->pView->PlacePiece(1, x, B_PAWN);

		(*pBoard)[x][6] = new Pawn(x, 6, true);
		this->pView->PlacePiece(6, x, W_PAWN);

		switch (x) {
			case 0:
			case 7: {
				(*pBoard)[x][0] = new Rook(x, 0, false);
				this->pView->PlacePiece(0, x, B_ROOK);

				(*pBoard)[x][7] = new Rook(x, 7, true);
				this->pView->PlacePiece(7, x, W_ROOK);
				break;
			}

			case 1:
			case 6: {
				(*pBoard)[x][0] = new Knight(x, 0, false);
				this->pView->PlacePiece(0, x, B_KNIGHT);

				(*pBoard)[x][7] = new Knight(x, 7, true);
				this->pView->PlacePiece(7, x, W_KNIGHT);
				break;
			}

			case 2:
			case 5: {
				(*pBoard)[x][0] = new Bishop(x, 0, false);
				this->pView->PlacePiece(0, x, B_BISHOP);

				(*pBoard)[x][7] = new Bishop(x, 7, true);
				this->pView->PlacePiece(7, x, W_BISHOP);
				break;
			}

			case 3: {
				(*pBoard)[x][0] = new Queen(x, 0, false);
				this->pView->PlacePiece(0, x, B_QUEEN);

				(*pBoard)[x][7] = new Queen(x, 7, true);
				this->pView->PlacePiece(7, x, W_QUEEN);
				break;
			}
			case 4: {
				(*pBoard)[x][0] = new King(x, 0, false);
				this->pView->PlacePiece(0, x, B_KING);

				(*pBoard)[x][7] = new King(x, 7, true);
				this->pView->PlacePiece(7, x, W_KING);
				break;
			}
		}
	}
	this->setLabel(false);

	bIgnoreTimeout = false;*/
}

void ChessController::on_SaveGame() {
	this->clearSelection();

	if(this->currentGame == ""){
		bIgnoreTimeout = true;
		this->currentGame = this->pView->SelectSaveFile();
	}

	if (this->currentGame.length() > 0) {
		this->pView->SetStatusBar(this->currentGame);
		//IO::saveGame(this->currentGame, &this->game);
		this->bSaved = true;
	}
	bIgnoreTimeout = false;
}

void ChessController::on_SaveGameAs() {
	this->clearSelection();

	bIgnoreTimeout = true;
	string tFile = this->pView->SelectSaveFile();

	if (tFile.length() > 0) {
		//IO::saveGame(tFile, &this->game);
		this->currentGame = tFile;
		this->pView->SetStatusBar(this->currentGame);
		this->bSaved = true;
	}
	bIgnoreTimeout = false;
}

void ChessController::on_LoadGame() {
	/*
	this->clearSelection();

	bIgnoreTimeout = true;
	string tFile = this->pView->SelectLoadFile();
	if (tFile.length() > 0) {
		this->currentGame = tFile;
		this->pView->SetStatusBar(this->currentGame);

		this->game = Game();
		this->clearBoard();

		IO::loadGame(tFile, &this->game);

		Board* pBoard = this->game.getBoard();

		for (int x = 0; x < 8; x++){
			for (int y = 0; y < 8; y++){
				if ((*pBoard)[x][y]) {
					ImageName tImage = ChessController::mineToTheirs(this->game.getPieceAt(x, y));
					this->pView->PlacePiece(y, x, tImage);
				}
			}
		}

		game.setTurn();
		this->setLabel(this->game.kingIsInCheck());
		this->bSaved = false;

		bIgnoreTimeout = false;
	}
	*/
}

void ChessController::on_UndoMove() {
	/*
	bIgnoreTimeout = true;

	this->clearSelection();

	if (!game.canUndo()) {
		bIgnoreTimeout = false;
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

	//this->game.changeSides();
	//this->setLabel(this->game.kingIsInCheck());
	this->bSaved = false;

	bIgnoreTimeout = false;*/
}

void ChessController::on_QuitGame() {
	bIgnoreTimeout = true;

	if (!bSaved) {
		string title = "Game not saved!";

		string message("Do you want to save your game?");

		vector<string> labels;
		labels.resize(3);
		labels[0] = "Yes";
		labels[1] = "Yes, but to a new file";
		labels[2] = "No";

		signed int selected = SelectDialog::SelectDialogRun(title, message, labels);

		if (selected == 1) {
			this->on_SaveGame();
		} else if (selected == 2) {
			this->on_SaveGameAs();
		}
	}
}

void ChessController::on_TimerEvent() {
	//if (!bIgnoreTimeout && bIgnoreTimeout && game.aiIsNext()) {
	//	this->makeMove(game.getAIMove());
	//}
}

void ChessController::SetView(IChessView* view) {
	this->pView = view;
}

void ChessController::checkGameOver() {
	/*if (!this->game.legalMoveExists()) {
		bool bCheckmate = this->game.kingIsInCheck();
		string title = bCheckmate ? "Checkmate" : "Stalemate";

		this->setLabel(bCheckmate, true);

		string message("Do you want to start a new game or look at the board?");

		vector<string> labels;
		labels.resize(2);
		labels[0]="New game";
		labels[1]="Cancel";

		signed int selected = SelectDialog::SelectDialogRun(title, message, labels);

		if (selected == 1) {
			this->on_NewGame();
		}
	}
	*/
}

void ChessController::clearBoard() {
	for (int x = 0; x < 8; x++){
		for (int y = 0; y < 8; y++){
			this->pView->ClearPiece(y, x);
		}
	}
}

void ChessController::clearSelection(int row, int col) {
	if (selectedX >= 0 && selectedY >= 0) {
		this->pView->UnHighlightSquare(selectedY, selectedX);
		while(validMoves.size()) {
			Move tMove = validMoves.front();
			validMoves.pop_front();

			this->pView->UnHighlightSquare(tMove.getEndY(), tMove.getEndX());

			if (tMove.getEndY() == row && tMove.getEndX() == col) {
				this->makeMove(tMove);
			}
		}

		this->selectedX = -1;
		this->selectedY = -1;
	}
}

void ChessController::setLabel(bool bCheck, bool bEndOfGame) {
	string text;
	if (bEndOfGame) {
		text = "Game over: ";
		if(bCheck) {
			text += "Checkmate";
		} else {
			text += "Stalemate";
		}
	} else {
		text = "Your turn.";
		if (bCheck) {
			text += " You are in check.";
		}
	}
/*
	if (game.isWhiteTurn()) {
		this->pView->SetTopLabel("");
		this->pView->SetBottomLabel(text);
	} else {
		this->pView->SetTopLabel(text);
		this->pView->SetBottomLabel("");
	}
	*/
}

void ChessController::makeMove(Move tMove) {
	/*
	ImageName tImage = ChessController::mineToTheirs(this->game.getPieceAt(selectedX, selectedY));
	game.move(tMove);

	this->pView->ClearPiece(tMove.getStartY(), tMove.getStartX());
	this->pView->PlacePiece(tMove.getEndY(), tMove.getEndX(), tImage);

	this->game.changeSides();
	this->setLabel(this->game.kingIsInCheck());
	this->checkGameOver();

	stringstream moveMessage;
	moveMessage << Game::typeToString(game.getPieceAt(tMove.getEndX(), tMove.getEndY()));
	moveMessage << " (";
	moveMessage << tMove.getStartY() << "," << tMove.getStartX();
	moveMessage << " : ";
	moveMessage << tMove.getEndY() << ","<< tMove.getEndX();
	moveMessage << ")\n";

	if (tMove.getCapturedPiece() != P_NAN) {
		moveMessage << "Piece Captured: ";
		if (tMove.isWhite()) {
			moveMessage << "white ";
		} else {
			moveMessage << "black ";
		}
		moveMessage << Game::typeToString(tMove.getCapturedPiece()) << "\n";
	}

	this->pView->WriteMessageArea(moveMessage.str());
	this->bSaved = false;*/
}

