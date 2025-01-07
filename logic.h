#include "grid.h"

enum player {
    EX, OH
};

typedef enum player player;

class Game {
    Grid board[9];
    int curr_grid; // the grid rotates according to the previous move
    player turn;
    void switch_turn();
    
    public: 
        // Sets the starting location to the top left box (Grid 0)
        Game();

        // Sets a move, switches the curr_grid to the space of this move, then swithces the turn
        bool set_move(cell move, int i);
        
        // Finds the outcome of the entire game based on the grids' statuses
        grid_status outcome();
};