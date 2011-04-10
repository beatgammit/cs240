#ifndef __LOAD_H__
#define __LOAD_H__

#include "string"

#include "game.h"

using namespace std;

class IO {
	public:
		/*
		 * Loads a game from the file passed to the constructor.
		 *
		 * @param filemname- file to load
		 * @param pGame- Pointer to a game to populate with the game data
		 * @return True if the game was loaded successfully, false if not
		 */
		static bool loadGame(string filename, Game* pGame);

		/*
		 * Saves the game to a file in XML format.
		 *
		 * @param filename- file to save the game to
		 * @param game- the game to save to file
		 * @return true if everything was hunky-dorey, false if not
		 */
		static bool saveGame(string filename, Game* pGame);

	private:
};

#endif
