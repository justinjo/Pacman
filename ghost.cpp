/*******************************************************************************
 * Ghost Class Implementation                                                  *
 ******************************************************************************/

#include <iostream>
#include <stdlib.h>      /* abs */
using namespace std;

#include "ghost.h"
#include "constants.h"
#include "termfuncs.h"

/* Constructor */
Ghost::Ghost()
{
        row = 0;
        col = 0;
        board_char = SPACE;
}

// set_location
// Purpose:     Initalizes location of Ghost
// Arguments:   Row (int), column (int)
// Returns:     None
void Ghost::set_location(int r, int c)
{
        row = r;
        col = c;
}

// set_random_location
// Purpose:     Initializes a random location of Ghost
// Arguments:   None
// Returns:     None
void Ghost::set_random_location()
{
        do {
                row = random_int(0, ROWS-1);
                col = random_int(0, COLS-1);
        } while (row == MIDROW || col == MIDCOL);
}

// move
// Purpose:     Moves the Ghost
// Arguments:   Board (char[][]), target row (int), target column (int)
// Returns:     If the Ghost has eaten the Pacman
bool Ghost::move(char board[ROWS][COLS], int target_r, int target_c)
{
        int new_row = row;
        int new_col = col; 
        board[row][col] = board_char;   // replace element of board
        if (abs(row-target_r) > abs(col-target_c)){     // never wraps
                if (row > target_r){
                        new_row--;
                } else if (row < target_r){
                        new_row++;
                }
                if (board[new_row][new_col] != GHOST)
                        row = new_row;
        } else {
                if (col > target_c){
                        new_col--;
                } else if (col < target_c){
                        new_col++;
                }
                if (board[new_row][new_col] != GHOST)
                        col = new_col;
        }
        place_on_board(board);
        return (target_r == row && target_c == col);
}

// place_on_board
// Purpose:     Places Ghost on board, stores newly replaced element
// Arguments:   Board (char[][])
// Returns:     None
void Ghost::place_on_board(char board[ROWS][COLS])
{
        if (board[row][col] != GHOST)
                board_char = board[row][col];       
        board[row][col] = GHOST;
}

// is_at
// Purpose:     Returns whether or not the Ghost is at a certain coordinate
// Arguments:   Row (int), column (int)
// Returns:     If the Ghost is at the location (bool)
bool Ghost::is_at(int r, int c)
{
        return ((r == row) && (c == col));
}
