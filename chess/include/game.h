#ifndef __GAME_H__
#define __GAME_H__

#include "string"
#include <stack>
#include <list>

#include "board.h"
#include "history.h"
#include "player.h"
#include "piece.h"
#include "move.h"

using namespace std;

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
		 * Creates a new game. Discards the current game.
		 *
		 * @param playMode-
		 */
		void createGame(int playMode = 0);

		/*
		 * Gets a list of legas moves for the piece at the specified position.
		 *
		 * @param x- the x position of the piece in question
		 * @param y- the y position of the piece in question
		 * @param pList- A pointer to the list to populate with possile moves
		 */
		void getLegalMoves(int x, int y, list<Move>* pList);

		/*
		 * Undoes a single move.
		 */
		void undoMove();

		/*
		 * Gets the board.
		 *
		 * @return The boare
		 */
		Board getBoard();

		/*
		 * Gets the move history.
		 *
		 * @return The move history
		 */
		History getMoveHistory();

	private:
		/* The game board */
		Board board;

		/* Move history. Used for undoing moves */
		History moveHistory;

		/* The white player */
		Player white;

		/* The black player */
		Player black;

		/* White pieces that have been captured */
		stack<Piece> whitePieces;

		/* Black pieces that have been captured */
		stack<Piece> blackPieces;
};

#endif
