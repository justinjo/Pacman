/*******************************************************************************
 * Dot Class Interface                                                         *
 ******************************************************************************/

#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include "constants.h"

class Dot {
        public:
                /* Constructor initalizes private members */
                Dot();

                /* chooses a random location for the dot on board */
                void set_random_location(char[ROWS][COLS]);

                /* places the Dot on the board, at its location */
                void place_on_board(char[ROWS][COLS]);

                /* returns if the dot is at this row and col */
                bool is_at(int, int);

                /* sets eaten to be the passed-in bool */
                void set_eaten(bool);

                /* returns if the dot has been eaten */
                bool was_eaten();
        private:
                int row, col;
                bool eaten;
};

#endif
