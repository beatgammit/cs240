#ifndef __HISTORY_H__
#define __HISTORY_H__

class History {
	public:
		/*
		 * Default constructor. Initializes stack.
		 */
		History();

		/*
		 * Destructor. Cleans up its own mess.
		 */
		~History();

		/*
		 * Calls push in Stack.
		 *
		 * @param tMove- the move to push on the history
		 */
		void push(Move tMove);

		/*
		 * Calls pop in Stack.
		 *
		 * @return The previous Move
		 */
		Move pop();

	private:
		Stack moveHistory;
};

#endif
