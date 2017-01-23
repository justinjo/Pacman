/*******************************************************************************
 * Pacman Class Interface                                                      *
 ******************************************************************************/
#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "constants.h"

class Pacman {
        public:
                Pacman();

                /* changes Pacman's location to be the center of the board */
                void center();

                /* moves Pacman based on an input command */
                bool move(char[ROWS][COLS], char command);

                /* places Pacman on the board, at Pacman's location */
                void place_on_board(char[ROWS][COLS]);

                /* returns the number of moves Pacman has made */
                int get_num_moves();

                /* location getters, setters and checkers */
                void set_col(int);
                void set_row(int);
                int  get_col();
                int  get_row();
                bool is_at(int,int);

                /* score checker and modifier */
                void add_to_score(int);
                int get_score();

                /* kills Pacman */
                void die();

                /* returns true if the pacman is alive, false, otherwise */
                bool is_alive();

                /* dots getter and setter */
                void set_dots(int);
                int get_dots();

        private:
                bool alive;
                char head;
                int row, col;
                int num_moves;
                int score;
                int dots_eaten;

                /* changes the Pacman's head given a command input */
                void rotate_head(char);

                /* returns true if a boulder obstructs the Pacman's move */
                bool boulder_ahead(char[ROWS][COLS],char);
};

#endif
