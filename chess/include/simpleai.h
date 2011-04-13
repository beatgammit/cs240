#ifndef __SIMPLEAI_H__
#define __SIMPLEAI_H__

#include "ai.h"
#include "move.h"

class SimpleAI : public AI {
	public:
		/*
		 * Default constructor.
		 */
		SimpleAI(bool bWhite) : AI(bWhite) {}

		/*
		 * Generate's a random move.  The parameter is not used.
		 *
		 * @param pBoard- the game board
		 * @param pPlayerMove- the opponent's last move
		 * @return The generated move
		 */
		virtual Move generateMove(TBoard* pBoard, Move* pPlayerMove = NULL);
};

#endif
