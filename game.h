/*******************************************************************************
 * Game Class Interface                                                        *
 ******************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "boulder.h"
//#include "../c-core-master/cpp/pubnub.hpp"
//#include "../c-core-master/posix/pubnub_alloc.h"

class Game {
        public:
                Game();

                /* prints manual and stalls until the user types a character */
                void print_manual();

                /* runs the Pacman game! */
                void run();
        private:
                char board[ROWS][COLS];
                int level;
                bool level_over;
                bool game_won;

                Pacman p;
                Ghost ghosts[NUM_GHOSTS];
                Dot dots[NUM_DOTS];
                Boulder boulders[NUM_BOULDERS];
                
                /* clears the board array */
                void clear_board();

                /* board printing functions */
                void print_board();
                char border(int,int);

                /* boulder setters */
                void set_boulders();

                /* dot initializer, setter, and eater */
                void init_dots();
                void set_dots();
                void eat_dot(int,int);

                /* ghost setter */
                void set_ghosts();

                /* level resetter, starter, player, and completer */
                void reset_level();
                void start_level();
                void play_level();
                void complete_level();
};

#endif
