/*******************************************************************************
 * Pacman Class Implementation                                                 *
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "pacman.h"
#include "constants.h"


/* Constructor */
Pacman::Pacman()
{
        center();
        alive = true;
        head = UP;
        num_moves = 0;
        score = 0;
        dots_eaten = 0;
}


// center()
// Purpose:     Changes Pacman's location to the center of the board
// Arguments:   None
// Returns:     None
void Pacman::center()
{
        row = MIDROW;
        col = MIDCOL;
        head = UP;
}

// move
// Purpose:     Moves Pacman based on input, wraps and detects ghosts/boulders
// Arguments:   Board (char[][]), input command (char)
// Returns:     If the Pacman ate a DOT (bool)
bool Pacman::move(char board[ROWS][COLS], char command)
{
        bool ate_dot = false;
        rotate_head(command);
        num_moves++;
        if (!boulder_ahead(board, command)){
                board[row][col] = SPACE;
                if (command == CMD_UP){         // move, wrap if needed
                        if (row == 0) {row = ROWS-1;} else {row--;}
                } else if (command == CMD_DWN){
                        if (row == ROWS-1) {row = 0;} else {row++;}
                } else if (command == CMD_RGT){
                        if (col == COLS-1) {col = 0;} else {col++;}
                } else if (command == CMD_LFT){
                        if (col == 0) {col = COLS-1;} else {col--;}
                }
        }
        if (board[row][col] == GHOST)
                die();
        if (board[row][col] == DOT){
                ate_dot = true;
                dots_eaten++;
        }
        return ate_dot;
}

// place_on_board
// Purpose:     Places Pacman on the board at Pacman's location
// Arguments:   Board (2D array)
// Returns:     None
void Pacman::place_on_board(char board[ROWS][COLS])
{
        board[row][col] = head;
}

// get_num_moves
// Purpose:     Returns the number of moves Pacman has made
// Arguments:   None
// Returns:     Number of moves Pacman has made (int)
int Pacman::get_num_moves()
{
        return num_moves;
}

// set_col
// Purpose:     Sets Pacman column
// Arguments:   Column (int)
// Returns:     None
void Pacman::set_col(int new_column)
{
        col = new_column;
}

// set_row
// Purpose:     Sets Pacman row
// Arguments:   Row (int)
// Returns:     None
void Pacman::set_row(int new_row)
{
        row = new_row;
}

// get_col
// Purpose:     Returns Pacman column
// Arguments:   None
// Returns:     Pacman column (int)
int Pacman::get_col()
{
        return col;
}

// get_row
// Purpose:     Returns Pacman row
// Arguments:   None
// Returns:     Pacman row (int)
int Pacman::get_row()
{
        return row;
}

// is_at
// Purpose:     Returns if the Pacman is at the given row and col
// Arguments:   Row (int) and column (int)
// Returns:     If the Pacman is at the given row and col (bool)
bool Pacman::is_at(int r, int c)
{
        return (r==row && c==col);
}

// add_to_score
// Purpose:     Takes an integer and adds it to Pacman's score
// Arguments:   Added score (int)
// Returns:     None
void Pacman::add_to_score(int n)
{
        score+=n;
}

// get_score
// Purpose:     Returns the Pacman's score
// Arguments:   None
// Returns:     Pacman's score (int)
int Pacman::get_score()
{
        return score;
}

// die
// Purpose:     Kills Pacman
// Arguments:   None
// Returns:     None
void Pacman::die()
{
        alive = false;
}

// is_alive
// Purpose:     Returns true if Pacman is alive, false if not
// Arguments:   None
// Returns:     If the Pacman is alive (bool)
bool Pacman::is_alive()
{
        return alive;
}

// set_dots
// Purpose:     Sets the number of dots eaten to a certain integer
// Arguments:   New number of dots eaten (int)
// Returns:     None
void Pacman::set_dots(int new_eaten)
{
        dots_eaten = new_eaten;
}

// get_dots
// Purpose:     Returns the number of dots eaten by the Pacman
// Arguments:   None
// Returns:     Number of dots eaten (int)
int Pacman::get_dots()
{
        return dots_eaten;
}

// rotate_head
// Purpose:     Changes the Pacman's head given a command input
// Arguments:   Command input (char)
// Returns:     None
void Pacman::rotate_head(char command)
{
        if (command == CMD_UP){
                head = UP;
        } else if (command == CMD_DWN){
                head = DOWN;
        } else if (command == CMD_LFT){
                head = LEFT;
        } else if (command == CMD_RGT){
                head = RIGHT;
        }
}

// boulder_ahead
// Purpose:     Returns true if a boulder obstructs Pacman's move
// Arguments:   Board (char[ROWS][COLS]), command move (char)
// Returns:     True if a boulder obstructs Pacman's move (bool)
bool Pacman::boulder_ahead(char board[ROWS][COLS], char command)
{
        if (command == CMD_UP){
                if (row == 0){
                        return (board[ROWS-1][col] == BOULDER);
                } else {
                        return (board[row-1][col] == BOULDER);
                }
        } else if (command == CMD_DWN){
                if (row == ROWS-1){
                        return (board[0][col] == BOULDER);
                } else {
                        return (board[row+1][col] == BOULDER);
                }
        } else if (command == CMD_RGT){
                if (col == COLS-1){
                        return (board[row][0] == BOULDER);
                } else {
                        return (board[row][col+1] == BOULDER);
                }
        } else if (command == CMD_LFT){
                if (col == 0){
                        return (board[row][COLS-1] == BOULDER);
                } else {
                        return (board[row][col-1] == BOULDER);
                }
        }
        return true;  // error case locks Pacman in place
}
