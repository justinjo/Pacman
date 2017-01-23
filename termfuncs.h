/*******************************************************************************
 * Terminal Function Class Interface                                           *
 ******************************************************************************/

#ifndef TERMFUNCS_H
#define TERMFUNCS_H

//   char getachar()     -- returns next char with no echo and no Enter needed
//   char getacharnow(n) -- like getachar but times out at n/10 sec
//                       -- if timeout, return '\0'
//   void screen_clear() -- clears the screen
//   void screen_home()  -- moves cursor to top of screen

const char      KEY_UP    = 130;
const char      KEY_DOWN  = 131;
const char      KEY_LEFT  = 132;
const char      KEY_RIGHT = 133;
const char      ESCAPE    = 27;

#include <string>

using std::string;

char getachar();
char getacharnow(int);
void screen_clear();
void screen_home();

int  random_int(int, int);
void seed_random(int);

#endif
