#include "logic.h"

// Sets the starting location to the top left box (Grid 0)
Game::Game() {
    for (int i = 0; i < 9; i++){
        board[i] = Grid();
    }
    
    curr_grid = 0;
    turn = EX;
}

void Game::switch_turn(){
    if (turn == EX){
        turn = OH;
    }
    else {
        turn = EX;
    }
}

// Sets a move, switches the curr_grid to the space of this move, then swithces the turn
bool Game::set_move(cell move, int i){
    if (board[curr_grid].set(move, i)){
        curr_grid = i;
        switch_turn();
        return true;
    }
    else {
        return false;
    }
}

// Finds the outcome of the entire game based on the grids' statuses
grid_status Game::outcome(){
    grid_status one;
    grid_status two;
    grid_status three;
    // Check horizontal
	for (int i = 0; i < 9; i += 3){
        one = board[i].get_status();
        two = board[i+1].get_status();
        three = board[i+2].get_status();
		if (one == two && two == three){
			return one;
		}
	}

	// Check vertical
	for (int j = 0; j < 3; j++){
        one = board[j].get_status();
        two = board[j+3].get_status();
        three = board[j+6].get_status();
		if (one == two && two == three){
			return one;
		}
	}

	// Check right diagonal
    one = board[0].get_status();
    two = board[4].get_status();
    three = board[8].get_status();
	if (one == two && two == three){
        return one;
	}

	// Check left diagonal
    one = board[2].get_status();
    two = board[4].get_status();
    three = board[6].get_status();
	if (one == two && two == three){
        return one;
    }

    for (int i = 0; i < 9; i++){
        if (!board[i].is_full()){
            return IN_PROGRESS;
        }
    }

	return TIE;
}