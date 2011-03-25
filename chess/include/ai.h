#ifndef __AI_H__
#define __AI_H__

class AI : public Player {
	public:
		/*
		 * Default constructor.
		 */
		AI() : Player() {}

		/*
		 * Returns true because this is an AI.
		 *
		 * @return true, this is an AI
		 */
		bool isAI(){return true;}

		/*
		 * Given a the other player's move, the AI should make a new move.
		 * 
		 * @param pPlayerMove- a pointer to the opponent's last move
		 * @return The generated move
		 */
		virtual Move generateMove(Move* pPlayerMove);
};

#endif
