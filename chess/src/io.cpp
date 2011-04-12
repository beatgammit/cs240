#include "io.h"

/// Public functions ///

void IO::loadGame(std::string filename, Game* pGame) {
	TiXmlDocument doc(filename.c_str());
	if (doc.LoadFile()) {
		parseXML(doc, pGame);
		std::cout << "Success: " << filename << std::endl;
	} else {
		std::cout << "Fail: " << filename << std::endl;
	}
}

void IO::saveGame(string filename, Game* pGame) {
}


/// Private functions ///

void IO::parseXML(TiXmlDocument doc, Game* pGame) {
	TiXmlElement* pRoot = doc.RootElement();
	if (pRoot) {
		parseBoardXML(pRoot->FirstChildElement("board"), pGame->getBoard());
		parseHistoryXML(pRoot->FirstChildElement("history"), pGame->getMoveHistory());
	}
}

void IO::parseBoardXML(TiXmlElement* pBoardNode, Board* pBoard){
	TiXmlElement* pNode = pBoardNode->FirstChildElement();
	while(pNode) {
		int x = 0;
		int y = 0;
		bool bWhite;
		Piece* pPiece = NULL;

		y = atoi(pNode->Attribute("row"));


		x = atoi(pNode->Attribute("column"));

		string color = pNode->Attribute("color");
		bWhite = (color == "white");

		string type = pNode->Attribute("type");
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

		pNode = pNode->NextSiblingElement();
	}
}

void IO::parseHistoryXML(TiXmlElement* pHistoryNode, History* pHistory) {

	TiXmlElement* pMoveNode = pHistoryNode->FirstChildElement("move");
	while(pMoveNode) {
		TiXmlElement* pStart = pMoveNode->FirstChildElement("piece");
		TiXmlElement* pEnd = pStart->NextSiblingElement("piece");
		TiXmlElement* pPieceTaken = pEnd->NextSiblingElement("piece");

		int startX = 0;
		int startY = 0;
		int endX = 0;
		int endY = 0;
		bool bWhite;
		PieceEnum tPiece = P_NAN;
		PieceEnum tCapturedPiece = P_NAN;

		startY = atoi(pStart->Attribute("row"));

		startX = atoi(pStart->Attribute("column"));

		string color = pStart->Attribute("color");
		bWhite = (color == "white");

		string type = pStart->Attribute("type");
		tPiece = typeFromString(type, bWhite);

		endY = atoi(pEnd->Attribute("row"));

		endX = atoi(pEnd->Attribute("column"));

		if (pPieceTaken) {
			type = pStart->Attribute("type");
			tCapturedPiece = typeFromString(type, !bWhite);
		}

		pHistory->push(startX, startY, endX, endY, tPiece, tCapturedPiece);

		pMoveNode = pMoveNode->NextSiblingElement("move");
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
