/*******************************************************************************
 * Dot Class Implementation                                                    *
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "dot.h"
#include "constants.h"
#include "termfuncs.h"

/* Constructor */
Dot::Dot()
{
        row = 0;
        col = 0;
        eaten = false;        
}

// set_random_location
// Purpose:     Chooses random location on board occupied by space to place dot
//                      Avoids middle of the board
// Arguments:   2D board array (char[][])
// Returns:     None
void Dot::set_random_location(char board[ROWS][COLS])
{
        do {
                row = random_int(0, ROWS-1);
                col = random_int(0, COLS-1);
        } while (board[row][col]!=SPACE || (row==MIDROW || col==MIDCOL));
}

// place_on_board
// Purpose:     Places dot on the board
// Arguments:   2D board array (char[][])
// Returns:     None
void Dot::place_on_board(char board[ROWS][COLS])
{
        board[row][col] = DOT;
}

// is_at
// Purpose:     Checks if the dot is at a row and col coordinate
// Arguments:   Row (int), Column (int)
// Returns:     If the dot coordinates match the row and col
bool Dot::is_at(int r, int c)
{
        return (row == r) && (col == c);
}

// set_eaten
// Purpose:     Sets eaten to the passed in boolean value
// Arguments:   If the dot is eaten or not (bool)
// Returns:     None
void Dot::set_eaten(bool is_eaten)
{
        eaten = is_eaten;
}

// was_eaten
// Purpose:     Returns if the dot is eaten or not
// Arguments:   None
// Returns:     If the dot is eaten or not (bool)
bool Dot::was_eaten()
{
        return eaten;
}
