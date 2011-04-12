#include "io.h"

/// Public functions ///

void IO::loadGame(std::string filename, Game* pGame) {
	std::ifstream in(filename.c_str());
	std::string contents((std::istreambuf_iterator<char>(in)),
    std::istreambuf_iterator<char>());

	xml_document<> doc;

	int len = contents.length();
	char* buf = new char[len];

	try {
		strncpy(buf, (char*)contents.c_str(), len);

		// I don't know why I need this flag, but it makes it more reliable
		doc.parse<parse_no_data_nodes>(buf);
		parseXML(doc, pGame);
		delete[] buf;
	}catch (...) {
		std::cout << "Fail: " << len << std::endl << buf << std::endl << contents << endl;
		delete[] buf;
	}
}

void IO::saveGame(string filename, Game* pGame) {
}


/// Private functions ///

void IO::parseXML(xml_document<> & doc, Game* pGame) {
	xml_node<>* pRoot = doc.first_node("chessgame");

	parseBoardXML(pRoot->first_node("board"), pGame->getBoard());
	parseHistoryXML(pRoot->first_node("history"), pGame->getMoveHistory());
}

void IO::parseBoardXML(xml_node<>* pBoardNode, Board* pBoard){
	xml_node<>* pNode = pBoardNode->first_node();
	while(pNode) {
		int x = 0;
		int y = 0;
		bool bWhite;
		Piece* pPiece = NULL;

		xml_attribute<>* pRow = pNode->first_attribute("row");
		y = atoi(pRow->value());

		xml_attribute<>* pColumn = pNode->first_attribute("column");
		x = atoi(pColumn->value());

		xml_attribute<>* pColor = pNode->first_attribute("color");
		string color = pColor->value();
		bWhite = (color == "white");

		xml_attribute<>* pType = pNode->first_attribute("type");
		string type = pType->value();
		if (type == "pawn") {
			pPiece = new Pawn(x, y, bWhite);
		} else if (type == "rook") {
			pPiece = new Rook(x, y, bWhite);
		} else if (type == "knight") {
			pPiece = new Knight(x, y, bWhite);
		} else if (type == "bishop") {
			pPiece = new Bishop(x, y, bWhite);
		} else if (type == "queen") {
			pPiece = new Queen(x, y, bWhite);
		} else if (type == "king") {
			pPiece = new King(x, y, bWhite);
		}

		(*pBoard)[x][y] = pPiece;

		pNode = pNode->next_sibling();
	}
}

void IO::parseHistoryXML(xml_node<>* pHistoryNode, History* pHistory) {
	xml_node<>* pMoveNode = pHistoryNode->first_node("move");
	while(pMoveNode) {
		xml_node<>* pStart = pMoveNode->first_node("piece");
		xml_node<>* pEnd = pStart->next_sibling("piece");
		xml_node<>* pPieceTaken = pEnd->next_sibling("piece");

		int startX = 0;
		int startY = 0;
		int endX = 0;
		int endY = 0;
		bool bWhite;
		PieceEnum tPiece = P_NAN;
		PieceEnum tCapturedPiece = P_NAN;

		xml_attribute<>* pRow = pStart->first_attribute("row");
		startY = atoi(pRow->value());

		xml_attribute<>* pColumn = pStart->first_attribute("column");
		startX = atoi(pColumn->value());

		xml_attribute<>* pColor = pStart->first_attribute("color");
		string color = pColor->value();
		bWhite = (color == "white");

		xml_attribute<>* pType = pStart->first_attribute("type");
		string type = pType->value();
		tPiece = typeFromString(type, bWhite);

		pRow = pEnd->first_attribute("row");
		endY = atoi(pRow->value());

		pColumn = pEnd->first_attribute("column");
		endX = atoi(pColumn->value());

		if (pPieceTaken) {
			pType = pStart->first_attribute("type");
			type = pType->value();
			tCapturedPiece = typeFromString(type, !bWhite);
		}

		pHistory->push(startX, startY, endX, endY, tPiece, tCapturedPiece);

		pMoveNode = pMoveNode->next_sibling("move");
	}
}

PieceEnum IO::typeFromString(string type, bool bWhite) {
	PieceEnum tPiece = P_NAN;

	if (type == "pawn") {
		tPiece = bWhite ? P_W_PAWN : P_B_PAWN;
	} else if (type == "rook") {
		tPiece = bWhite ? P_W_ROOK : P_B_ROOK;
	} else if (type == "knight") {
		tPiece = bWhite ? P_W_KNIGHT : P_B_KNIGHT;
	} else if (type == "bishop") {
		tPiece = bWhite ? P_W_BISHOP : P_B_BISHOP;
	} else if (type == "queen") {
		tPiece = bWhite ? P_W_QUEEN : P_B_QUEEN;
	} else if (type == "king") {
		tPiece = bWhite ? P_W_KING : P_B_KING;
	}

	return tPiece;
}
