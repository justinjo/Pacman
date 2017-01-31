/*******************************************************************************
 * Boulder Class Interface                                                     *
 ******************************************************************************/
#ifndef BOULDER_H_INCLUDED
#define BOULDER_H_INCLUDED

#include "constants.h"
#include "termfuncs.h"

class Boulder {
        public:
                /* Constructor: chooses a random location and size for the
                 * boulder that doesn't overlap the middle */
                Boulder();

                /* Places Boulder on the board, at its location. Does not
                 * attempt to access out of bounds slots of the array if the
                 * boulder goes off the edge. */
                void place_on_board(char[ROWS][COLS]);

        private:
                int top_left_r, top_left_c, height, width;

                /* for checking if boulder overlaps the middle of the board */
                bool overlaps_middle();
};

#endif
