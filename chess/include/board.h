#ifndef __BOARD_H__
#define __BOARD_H__

/*
 * Represents a Chess board as a 2-dimensional array of Piece pointers.
 */
class Board {
	public:
		/*
		 * Default constructor. Initializes board.
		 */
		Board();

		/*
		 * Destructor. Frees board.
		 */
		~Board();
	private:
		/* 2-Dimensional array */
		Piece** board[][];
};

#endif
