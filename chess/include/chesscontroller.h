#ifndef __CHESSCONTROLLER_H__
#define __CHESSCONTROLLER_H__

#include <iostream>
#include <sstream>

#include <list>
#include <vector>

#include "IChessController.h"
#include "SelectDialog.h"

#include "game.h"
#include "io.h"

using namespace std;

/*
 * Interfaces with the GUI and with the underlying game.
 */
class ChessController : public IChessController {
	public:
		/*
		 * Constructor.
		 *
		 * @param argc- the number of parameters
		 * @param argv- the parameters
		 */
		ChessController(int argc, char** argv);

		/*
		 * Indicate to the player that the user clicked on the given
		 * row and column with the mouse.
		 */
		virtual void on_CellSelected(int row, int col, int button);

		/*
		 * @param row where drag began
		 * @param col where drag began
		 */
		virtual void on_DragStart(int row,int col);

		/*
		 * @param row where drag ended
		 * @param col where drag ended
		 * @return true if the drag resulted in a successful drop
		 */
		virtual bool on_DragEnd(int row,int col);

		/*
		 * Handle when the user selected the new game button.
		 */
		virtual void on_NewGame();

		/*
		 * Handle when the user selected the save game button.
		 */
		virtual void on_SaveGame();

		/*
		 * Handle when the user selected the save game as button.
		 */
		virtual void on_SaveGameAs();

		/*
		 * Handle when the user selected the load game button.
		 */
		virtual void on_LoadGame();

		/**
		* Handle when the user selected the undo move button.
		*/
		virtual void on_UndoMove();

		/**
		 * Handle when the user selects to quit the game, either through the
		 * quit button, the close X button, or the file menu.
		 */
		virtual void on_QuitGame();

		/**
		 * Handle when a timer event has been signaled.
		 */
		virtual void on_TimerEvent();

		/**
		 * Set the IChessView that this IChessController will handle inputs for.
		 */
		virtual void SetView(IChessView* view);

		~ChessController() {}

		static ImageName mineToTheirs(PieceEnum tEnum);

	private:
		void clearBoard();

		void clearSelection(int row = 0, int col = 0);

		void placePiece(Piece* pPiece);

		void selectPiece(Piece* pPiece);

		void setLabel(bool bCheck, bool bEndOfGame = false);

		void checkGameOver();

		void makeMove(Move tMove);

		/* The chess game */
		Game game;

		IChessView* pView;

		string currentGame;

		list<Move> validMoves;

		int selectedX;
		int selectedY;

		bool bSaved;
};

#endif
