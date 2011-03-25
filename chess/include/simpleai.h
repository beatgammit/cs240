#ifndef __SIMPLEAI_H__
#define __SIMPLEAI_H__

#include "ai.h"
#include "move.h"

class SimpleAI : public AI {
	public:
		/*
		 * Default constructor.
		 */
		SimpleAI() : AI() {}

		/*
		 * Generate's a random move.  The parameter is not used.
		 * 
		 * @param pPlayerMove- the opponent's last move
		 * @return The generated move
		 */
		Move generateMove(Move* pPlayerMove);
};

#endif
