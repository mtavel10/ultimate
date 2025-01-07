#include "grid.h"
#include <iostream>

Grid::Grid() {
	for (int i = 0; i < 9; i++){
		g[i] = EMPTY;
	}
	status = IN_PROGRESS;
	move_count = 0;
}

grid_status Grid::calc_winner() {
	// Check horizontal
	for (int i = 0; i < 9; i += 3){
		if (g[i] == g[i+1] && g[i+1] == g[i+2]){
			if (g[i] == X){
				status = X_WON;
				return X_WON;
			}
			else if (g[i] == O){
				status = O_WON;
				return O_WON;
			}
		}
	}

	// Check vertical
	for (int j = 0; j < 3; j++){
		if (g[j] == g[j+3] && g[j+3] == g[j+6]){
			if (g[j] == X){
				status = X_WON;
				return X_WON;
			}
			else if (g[j] == O){
				status = O_WON;
				return O_WON;
			}
		}
	}

	// Check right diagonal
	if (g[0] == g[4] && g[4] == g[8]){
		if (g[0] == X){
			status = X_WON;
			return X_WON;
		}
		else if (g[0] == O){
			status = O_WON;
			return O_WON;
		}
	}

	// Check left diagonal
	if (g[2] == g[4] && g[4] == g[6]){
		if (g[2] == X){
			status = X_WON;
			return X_WON;
		}
		else if (g[2] == O){
			status = O_WON;
			return O_WON;
		}
	}

	// Check tie
	if (is_full()) {
		status = TIE;
		return TIE;
	}

	return IN_PROGRESS;
}

bool Grid::set(cell move, int i) {
	if (g[i] != EMPTY || is_full()){
		return false;
	}
	g[i] = move;
	move_count++;
	return true;
}

bool Grid::is_full() {
	return (move_count == 9);
}

cell Grid::get_cell(int i) { return g[i]; }
const grid_status Grid::get_status() {return status; }
const char Grid::get_move_count() { return move_count; }