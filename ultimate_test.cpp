#include <criterion/criterion.h>
#include "grid.h"

/* Grid tests: constructor, set, is_full, calc_winner */
Test(constructor, test1) {
    Grid grid;
    for (int i = 0; i < 9; i++){
        cr_assert(grid.get_cell(i) == EMPTY);
    }
    cr_assert(grid.get_status() == IN_PROGRESS);
    cr_assert(!grid.get_move_count());
}

Test(set, test1){
    Grid grid;
    grid.set(X, 0);
    grid.set(O, 1);
    cr_assert(grid.get_cell(0) == X);
    cr_assert(grid.get_cell(1) == O);
}

Test(set, test2){
    Grid grid;
    grid.set(X, 0);
    cr_assert(!grid.set(O, 0));
    cr_assert(grid.get_cell(0) == X);
}

Test(set, tet3){
    Grid grid;
    grid.set(O, 0);
    grid.set(X, 1);
    grid.set(X, 2);
    grid.set(O, 3);
    grid.set(X, 4);
    grid.set(O, 5);
    grid.set(X, 6);
    grid.set(O, 7);
    grid.set(O, 8);
    cr_assert(grid.get_move_count() == 9);
    cr_assert(!grid.set(O, 0));
}

Test(is_full, test1){
    Grid grid;
    grid.set(O, 0);
    grid.set(X, 1);
    grid.set(X, 2);
    grid.set(O, 3);
    grid.set(X, 4);
    grid.set(O, 5);
    grid.set(X, 6);
    grid.set(O, 7);
    grid.set(O, 8);
    cr_assert(grid.is_full());
}

Test(is_full, test2){
    Grid grid;
    grid.set(O, 0);
    cr_assert(!grid.is_full());
}

Test(calc_winner, test1){
    Grid grid;
    cr_assert(grid.calc_winner() == IN_PROGRESS);
    cr_assert(grid.get_status() == IN_PROGRESS);
}

Test(calc_winner, horizontal_test1){
    Grid grid;
    grid.set(O, 0);
    grid.set(O, 1);
    grid.set(O, 2);
    cr_assert(grid.calc_winner() == O_WON);
    cr_assert(grid.get_status() == O_WON);
}

Test(calc_winner, horizontal_tes21){
    Grid grid;
    grid.set(O, 3);
    grid.set(O, 4);
    grid.set(O, 5);
    cr_assert(grid.calc_winner() == O_WON);
    cr_assert(grid.get_status() == O_WON);
}

Test(calc_winner, horizontal_test3){
    Grid grid;
    grid.set(X, 6);
    grid.set(X, 7);
    grid.set(X, 8);
    cr_assert(grid.calc_winner() == X_WON);
    cr_assert(grid.get_status() == X_WON);
}

Test(calc_winner, vertical_test1){
    Grid grid;
    grid.set(O, 0);
    grid.set(O, 3);
    grid.set(O, 6);
    cr_assert(grid.get_cell(0) == O);
    cr_assert(grid.get_cell(3) == O);
    cr_assert(grid.get_cell(6) == O);
    cr_assert(grid.calc_winner() == O_WON);
    cr_assert(grid.get_status() == O_WON);
}

Test(calc_winner, vertical_test2){
    Grid grid;
    grid.set(O, 1);
    grid.set(O, 4);
    grid.set(O, 7);
    cr_assert(grid.calc_winner() == O_WON);
    cr_assert(grid.get_status() == O_WON);
}

Test(calc_winner, vertical_test3){
    Grid grid;
    grid.set(O, 2);
    grid.set(O, 5);
    grid.set(O, 8);
    cr_assert(grid.calc_winner() == O_WON);
    cr_assert(grid.get_status() == O_WON);
}

Test(calc_winner, diagonal_test1){
    Grid grid;
    grid.set(X, 0);
    grid.set(X, 4);
    grid.set(X, 8);
    cr_assert(grid.calc_winner() == X_WON);
    cr_assert(grid.get_status() == X_WON);
}

Test(calc_winner, diagonal_test2){
    Grid grid;
    grid.set(X, 2);
    grid.set(X, 4);
    grid.set(X, 6);
    cr_assert(grid.calc_winner() == X_WON);
    cr_assert(grid.get_status() == X_WON);
}

Test(calc_winner, draw_test1){
    Grid grid;
    grid.set(X, 0);
    grid.set(O, 3);
    grid.set(X, 6);

    grid.set(O, 1);
    grid.set(O, 4);
    grid.set(X, 7);

    grid.set(O, 2);
    grid.set(X, 5);
    grid.set(O, 8);

    cr_assert(grid.calc_winner() == TIE);
    cr_assert(grid.get_status() == TIE);
}