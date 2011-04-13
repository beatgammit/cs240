#ifndef __AI_H__
#define __AI_H__

#include "player.h"
#include "move.h"

class AI : public Player {
	public:
		/*
		 * Default constructor.
		 */
		AI(bool bWhite) : Player(bWhite) {}

		/*
		 * Returns true because this is an AI.
		 *
		 * @return true, this is an AI
		 */
		virtual bool isAI(){return true;}

		/*
		 * Given a the other player's move, the AI should make a new move.
		 *
		 * @param pBoard- game board
		 * @param pPlayerMove- a pointer to the opponent's last move
		 * @return The generated move
		 */
		virtual Move generateMove(TBoard* pBoard, Move* pPlayerMove = NULL) {}
};

#endif
