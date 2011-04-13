#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "piece.h"

typedef Piece* TBoard[8][8];

/*
 * Represents a player.  This is mainly used for abstraction.
 */
class Player {
	public:
		/*
		 * Default constructor. Doesn't do much.
		 */
		Player(bool isWhite) : bWhite(isWhite) {};

		/*
		 * Returns true if this player is an AI.
		 */
		virtual bool isAI() {}

		bool isWhite() {return bWhite;}

		~Player(){};

	private:
		bool bWhite;
};

#endif
