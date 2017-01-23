/*******************************************************************************
 * Ghost Class Interface                                                       *
 ******************************************************************************/
#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "constants.h"

class Ghost {
        public:
                Ghost();

                /* location setters */
                void set_location(int r, int c);
                void set_random_location();

                /* moves ghost according to algorithm */
                bool move(char[ROWS][COLS], int target_r, int target_c);
                
                /* places ghost on board */
                void place_on_board(char[ROWS][COLS]);

                /* returns true if ghost is at given coordinate */
                bool is_at(int,int);
        private:
                int row, col;
                char board_char; // board character the ghost is hovering over
};
#endif
