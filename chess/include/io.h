#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>

#include <fstream>
#include "string"
#include "string.h"

#include "rapidxml.hpp"

#include "game.h"

#include "history.h"
#include "move.h"

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

using namespace rapidxml;

class IO {
	public:
		/*
		 * Loads a game from the file passed to the constructor.
		 *
		 * @param filemname- file to load
		 * @param pGame- Pointer to a game to populate with the game data
		 */
		static void loadGame(std::string filename, Game* pGame);

		/*
		 * Saves the game to a file in XML format.
		 *
		 * @param filename- file to save the game to
		 * @param game- the game to save to file
		 */
		static void saveGame(std::string filename, Game* pGame);

	private:
		static void parseXML(xml_document<> & doc, Game* pGame);

		static void parseBoardXML(xml_node<>* pBoardNode, Board* pBoard);

		static void parseHistoryXML(xml_node<>* pHistoryNode, History* pHistory);

		static PieceEnum typeFromString(string s, bool bWhite);
};

#endif
