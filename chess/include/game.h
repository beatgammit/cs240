#ifndef __GAME_H__
#define __GAME_H__

/*
 * Main runner for the Chess game.
 */
class Game {
	public:
		/*
		 * Default constructor.  Takes an optional filename to load a saved game
		 * 
		 * @param string- Filename of a saved game
		 */
		Game(string savedGame = "");

		/*
		 * 
		 */
	
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
		Stack<Piece> whitePieces;

		/* Black pieces that have been captured */
		Stack<Piece> blackPieces;
};

#endif
