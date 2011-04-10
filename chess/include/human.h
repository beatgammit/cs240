#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.h"

class Human : public Player {
	public:
		/*
		 * Default constructor.  Not very interesting...
		 */
		Human() : Player() {}

		/*
		 * Returns false, because this is a human.
		 *
		 * @return true, this is a human
		 */
		virtual bool isAI() {return false;}
};

#endif
