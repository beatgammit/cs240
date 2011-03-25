#ifndef __SAVE_H__
#define __SAVE_H__

class Save {
	public:
		/*
		 * Constructor.
		 * 
		 * @param filename- the filename to save game to
		 */
		Save(string filename);

		/*
		 * Saves the game to a file in XML format.
		 * 
		 * @param game- the game to save to file
		 * @return true if everything was hunky-dorey, false if not
		 */
		bool saveGame(Game & game);
	
	private:
		/* The file to save the game to */
		string filename;
};

#endif
