/*******************************************************************************
 * Game Class Implementation                                                   *
 *****************************************************************************/

#include <iostream>
using namespace std;

#include "game.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "termfuncs.h"

/* Constructor */
Game::Game()
{
        level = 1;
        level_over = false;
        game_won = false;

/*        pubnub::context pn("pub-c-211da9ce-adcf-44ab-b2d1-fc1c0a8eaadc", 
                        "sub-c-22d37992-dea5-11e6-b2ae-0619f8945a4f");        */
}

// print_manual
// Purpose:     Prints the manual and stalls until the user types a character
// Arguments:   None
// Returns:     None
void Game::print_manual()
{
        screen_clear();
        cout << "PACMAN GAME\n"
                "            \n"
                " Move left:    " << CMD_LFT << "\n"
                " Move right:   " << CMD_RGT << "\n"
                " Move up:      " << CMD_UP  << "\n"
                " Move down:    " << CMD_DWN << "\n"
                "\n"
                " Collect all the dots. They look like: " << DOT << "\n"
                " Avoid the ghosts.     They look like: " << GHOST << "\n"
                "\n"
                " Good luck!\n"
                "\n"
                " Press any key to continue...\n";

        getachar();
}

// run
// Purpose:     Runs the main game
// Arguments:   None
// Returns:     None
void Game::run()
{
        while (!game_won && p.is_alive()){
                reset_level();
                start_level();
                play_level();
                if (p.is_alive())
                        complete_level();
        }
        if (game_won){
                cout << "You win!\n";
        } else {
                cout << "You lost :(\n";
        }
}

// clear_board
// Purpose:     Initializes the board array by clearing it
// Arguments:   None
// Returns:     None
void Game::clear_board()
{
        for (int r=0; r<ROWS; r++){
                for (int c=0; c<COLS; c++){
                        board[r][c] = SPACE;
                }
        }
}

// print_board
// Purpose:     Prints the entire game board including its borders
// Arguments:   None
// Returns:     None
void Game::print_board()
{
        for (int r=-1; r<=ROWS; r++){
                for (int c=-1; c<=COLS; c++){
                        if ((r==-1||r==ROWS)||(c==-1||c==COLS)){
                                cout << border(r,c);
                        } else {
                                cout << board[r][c];
                        }
                }
                cout << endl;
        }
        cout << "Score: " << p.get_score() << endl;
}

// border
// Purpose:     Returns the border character for a given coordinate
// Arguments:   Row coordinate (int), Column coordinate (int)
// Returns:     Border character (char)
char Game::border(int row, int col)
{
        if (row == -1 || row == ROWS){
                if (col == -1 || col == COLS){
                        return BORD_CORN;
                } else {
                        return BORD_TOP;
                }
        } else {
                return BORD_SIDE;
        }
}

// set_boulders
// Purpose:     Places the boulders for each level
// Arguments:   None
// Returns:     None
void Game::set_boulders()
{
        for (int i=0; i<BOULDERS_PER_LEVEL*level; i++)
                boulders[i].place_on_board(board);
}

// init_dots
// Purpose:     Sets location of the dots avoiding boulders, sets them not eaten
// Arguments:   None
// Returns:     None
void Game::init_dots()
{
        set_boulders(); // to avoid boulders in each level
        for (int i=0; i<NUM_DOTS; i++){
                dots[i].set_random_location(board);
                dots[i].set_eaten(false);
                dots[i].place_on_board(board); // to ensure no dots overlap
        }
        clear_board();
}

// set_dots
// Purpose:     Places all of the dots and sets them to not eaten
// Arguments:   None
// Returns:     None
void Game::set_dots()
{
        for (int i=0; i<DOTS_PER_LEVEL*level; i++)
                dots[i].place_on_board(board);
}

// eat_dot
// Purpose:     Eats a dot at a given location
// Arguments:   Given row (int), given column (int)
// Returns:     None
void Game::eat_dot(int r, int c)
{
        for (int i=0; i<DOTS_PER_LEVEL*level; i++)
                if (dots[i].is_at(r,c))
                        dots[i].was_eaten();
        p.add_to_score(DOT_REWARD);
}

// set_ghosts
// Purpose:     Sets first 4 ghosts in corners, then randomly sets location 
// Arguments:   None
// Returns:     None
void Game::set_ghosts()
{
        for (int i=0; i<NUM_GHOSTS; i++){
                if (i==0){
                        ghosts[i].set_location(0,0);
                } else if (i==1){
                        ghosts[i].set_location(0,COLS-1);
                } else if (i==2){
                        ghosts[i].set_location(ROWS-1,0);
                } else if (i==3){
                        ghosts[i].set_location(ROWS-1,COLS-1);
                } else {
                        ghosts[i].set_random_location();
                }
                ghosts[i].place_on_board(board);
        }
}

// reset_level
// Purpose:     Sets up each level
// Arguments:   None
// Returns:     None
void Game::reset_level()
{
        clear_board();
        init_dots();    // prepare dots, boulders, and ghosts
        set_dots();
        set_boulders();
        set_ghosts();
        p.center();     // prepare pacman
        p.place_on_board(board);
        p.set_dots(0);
        level_over = false;
}

// start_level
// Purpose:     Begins each level, waits for user input to start
// Arguments:   None
// Returns:     None
void Game::start_level()
{
        screen_clear();
        print_board();
        cout << "Level " << level << ": Press any key to start\n";
        getachar();
        screen_clear(); // print initial state of boar
        print_board(); 
}

// play_level
// Purpose:     Plays each level of the game
// Arguments:   None
// Returns:     None 
void Game::play_level()
{
        char move;
        while (p.is_alive() && !level_over){
                // Pacman moves
                move = getacharnow(2);
                if (move == CMD_QUIT){
                        level_over = true;
                        p.die();
                        return;
                } else if (move == CHEAT){
                        level_over = true;
                }
                if (p.move(board, move)){
                        eat_dot(p.get_row(), p.get_col());
                        level_over = !(p.get_dots() < level*DOTS_PER_LEVEL);
                }
                if (p.is_alive())   // Show Ghost if Pacman is eaten
                        p.place_on_board(board);
                screen_home();
                print_board();
                
                // Ghosts move
                if (p.get_num_moves()%GHOST_FREQ==0 && !level_over){
                        for (int i=0; i<NUM_GHOSTS; i++){
                                if (ghosts[i].move(board, p.get_row(),
                                                          p.get_col()))
                                        p.die();        // Pacman eaten
                                ghosts[i].place_on_board(board);
                        }
                }
                screen_home();
                print_board();
        }
}

// complete_level
// Purpose:     Completes each level, adds to Pacman's score, checks if game won
// Arguments:   None
// Returns:     None 
void Game::complete_level()
{
        p.add_to_score(LEVEL_REWARD);
        level++;
        game_won = level > NUM_LEVELS;
}
