/*******************************************************************************
 * Boulder Class Implementation                                                *
 ******************************************************************************/



#include <iostream>
#include "boulder.h"
using namespace std;

/* Constructor */
Boulder::Boulder()
{
        /* keep randomly choosing a location until we find a location and size
         * that doesn't overlap the middle */
        do {
                top_left_r = random_int(0, ROWS-1);
                top_left_c = random_int(0, COLS-1);
                height = random_int(MIN_BOULDER_HEIGHT, MAX_BOULDER_HEIGHT);
                width  = random_int(MIN_BOULDER_WIDTH, MAX_BOULDER_WIDTH);
        } while ( overlaps_middle() );
}

/* place_on_board
 * Purpose:     Places the boulder onto the 2D board
 * Arguments:   2D board (char[][])
 * Returns:     None
 */
void Boulder::place_on_board(char board[ROWS][COLS])
{
        for (int r = top_left_r; r <= top_left_r + height; r++) {
                for (int c = top_left_c; c <= top_left_c + width; c++) {
                        if (r < ROWS && c < COLS) {
                                board[r][c] = BOULDER;
                        }
                }
        }
}

/* overlaps_middle
 * Purpose:     Determines if current boulder overlaps middle position on board
 * Arguments:   None
 * Returns:     True if boulder overlaps the middle position, false otherwise
 */
bool Boulder::overlaps_middle()
{
        bool center_row = (ROWS / 2) >= top_left_r &&
                          (ROWS / 2) <= (top_left_r + height);

        bool center_col = (COLS / 2) >= top_left_c &&
                          (COLS / 2) <= (top_left_c + width);

        return (center_row and center_col);
}