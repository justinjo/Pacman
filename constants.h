/*******************************************************************************
 * Constants Configuration                                                     *
 ******************************************************************************/
#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int  ROWS               = 21;
const int  COLS               = 61;
const int  MIDROW             = ROWS/2;
const int  MIDCOL             = COLS/2;

const char SPACE              = ' ';

const char BORD_TOP           = '-';
const char BORD_CORN          = '+';
const char BORD_SIDE          = '|';

const char DOT                = 'o';
const char BOULDER            = 'X';

const char CMD_UP             = 'w';
const char CMD_DWN            = 's';
const char CMD_LFT            = 'a';
const char CMD_RGT            = 'd';
const char CMD_QUIT           = 'q';
const char CHEAT              = 'G';

const char GHOST              = 'm';
const char LEFT               = '>';
const char RIGHT              = '<';
const char UP                 = 'v';
const char DOWN               = '^';

const int  NUM_GHOSTS         = 4;
const int  NUM_LEVELS         = 10;
const int  DOTS_PER_LEVEL     = 5;
const int  NUM_DOTS           = DOTS_PER_LEVEL * NUM_LEVELS;
const int  BOULDERS_PER_LEVEL = 1;
const int  NUM_BOULDERS       = BOULDERS_PER_LEVEL * NUM_LEVELS;

const int  MIN_BOULDER_WIDTH  = COLS / 10;
const int  MAX_BOULDER_WIDTH  = COLS / 4;
const int  MIN_BOULDER_HEIGHT = ROWS / 10;
const int  MAX_BOULDER_HEIGHT = ROWS / 4;

/* the user gets points for eating a dot and beating a level */
const int  DOT_REWARD         = 1;
const int  LEVEL_REWARD       = 10;

/* the ghosts moves once for every GHOST_FREQ moves the user makes */
const int  GHOST_FREQ = 2;

/* pace of game set at SPEED/10 seconds */
const int  SPEED      = 3;

#endif
