#ifndef __LOAD_H__
#define __LOAD_H__

class Load {
	public:
		/*
		 * Constructor.  Takes a file name.
		 * 
		 * @param filename- A path to the file to load
		 */
		Load(string filename);

		/*
		 * Loads a game from the file passed to the constructor.
		 * 
		 * @param pGame- Pointer to a game to populate with the game data
		 * @return True if the game was loaded successfully, false if not
		 */
		bool loadGame(Game* pGame);
	
	private:
		/* The file to load the game from */
		string filename;
};

#endif
