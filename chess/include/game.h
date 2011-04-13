#ifndef __GAME_H__
#define __GAME_H__

#include "string"
#include <stack>
#include <list>

#include "history.h"
#include "player.h"
#include "piece.h"
#include "move.h"

using namespace std;

// typedefs are cool... let's use ane =D
typedef Piece* Board[8][8];

/*
 * Main runner for the Chess game.
 */
class Game {
	public:
		/*
		 * Default constructor.
		 *
		 * Creates the game according to the play mode:
		 * - 0: Human (White) vs Human (Black)
		 * - 1: Human (White) vs Computer (Black)
		 * - 2: Computer (Black) vs Human (White)
		 * - 3: Computer (Black) vs Computer (Black)
		 *
		 *
		 * @param playMode- as described above (defaults to human vs human)
		 */
		Game(int playMode = 0);

		/*
		 * Takes an filename to load a saved game.
		 *
		 * @param string- Filename of a saved game
		 */
		Game(string savedGame);

		/*
		 * Destructor.  Frees everything in the board.
		 */
		~Game();

		/*
		 * Creates a new game. Discards the current game.
		 *
		 * @param playMode-
		 */
		void createGame(int playMode = 0);

		/*
		 * Gets a list of legal moves for the piece at the specified position.
		 *
		 * @param x- the x position of the piece in question
		 * @param y- the y position of the piece in question
		 * @param pList- A pointer to the list to populate with possile moves
		 */
		void getLegalMoves(int x, int y, list<Move>* pList);

		void move(Move tMove);

		bool kingIsInCheck() {kingIsInCheck(this->isWhiteTurn());}

		bool kingIsInCheck(bool bWhite);

		/*
		 * Undoes a single move.
		 */
		Move undoMove();

		bool canUndo();

		/*
		 * Gets the board.
		 *
		 * @return The boare
		 */
		Board* getBoard();

		/*
		 * Gets the move history.
		 *
		 * @return The move history
		 */
		History* getMoveHistory();

		bool isWhiteTurn();

		void changeSides();

		Piece* findPiece(PieceEnum tPiece);

		list<Move> getLegalMoves(int x, int y);

		PieceEnum getPieceAt(int x, int y);

		bool canMove(int x, int y);

		bool legalMoveExists();

		void setTurn();

		static string typeToString(PieceEnum type);

	private:
		bool kingInCheckKnight(Piece* pKing);
		bool kingInCheckVertical(Piece* pKing);
		bool kingInCheckHorizontal(Piece* pKing);
		bool kingInCheckDiagonal(Piece* pKing);
		bool kingInCheckPawn(Piece* pKing);

		/* The game board */
		Board board;

		/* Move history. Used for undoing moves */
		History moveHistory;

		/* The white player */
		Player white;

		/* The black player */
		Player black;

		/* White pieces that have been captured */
		stack<Piece*> whitePieces;

		/* Black pieces that have been captured */
		stack<Piece*> blackPieces;

		bool bWhiteTurn;
};

#endif
