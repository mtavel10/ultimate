/* The internal data structures that hold game information. */
#ifndef GRID_H
#define GRID_H

enum cell {
	X, O, EMPTY
};

typedef enum cell cell;

enum grid_status {
	X_WON, O_WON, IN_PROGRESS, TIE
};

typedef enum grid_status status;

class Grid {
	cell g[9]; // spots in the grid are stored as numbers 0-8 going from top to bottom, left to right
	grid_status status;
	char move_count;

	public:
		Grid();

		/* Calculates the winner of the grid by checking for three in a row
		 * horizontally, vertically, and diagonally */
		grid_status calc_winner();

		/* If the a move is possible in this location, updates the cell */
		bool set(cell move, int i);

		/* The board is full once there are nine moves made */
		bool is_full();

		/* Getter methods for testing purposes s*/
		cell get_cell(int i);
		const grid_status get_status();
		const char get_move_count();
};

#endif // GRID_H