#ifndef __PLAYER_H__
#define __PLAYER_H__

/*
 * Represents a player.  This is mainly used for abstraction.
 */
class Player {
	public:
		/*
		 * Default constructor. Doesn't do much.
		 */
		Player() {}

		/*
		 * Returns true if this player is an AI.
		 */
		virtual bool isAI();
};

#endif
