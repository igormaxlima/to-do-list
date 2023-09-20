#include <stdio.h>
#include "term.h"

void tc_get_cols_rows(int *cols, int *rows)
{

  struct winsize size;
  ioctl(1, TIOCGWINSZ, &size);
  *cols = size.ws_col;
  *rows = size.ws_row;

} // tec_get_cols_rows*/

void tc_echo_off()
{

  struct termios term;
  tcgetattr(1, &term);
  term.c_lflag &= ~ECHO;
  tcsetattr(1, TCSANOW, &term);

} // tc_echo_off*/

void tc_echo_on()
{

  struct termios term;
  tcgetattr(1, &term);
  term.c_lflag |= ECHO;
  tcsetattr(1, TCSANOW, &term);

} // tc_echo_on*/

void tc_canon_on()
{

  struct termios term;
  tcgetattr(1, &term);
  term.c_lflag |= ICANON;
  tcsetattr(1, TCSANOW, &term);

} // tc_canon_on*/

void tc_canon_off()
{

  struct termios term;
  tcgetattr(1, &term);
  term.c_lflag &= ~ICANON;
  tcsetattr(1, TCSANOW, &term);

} // tc_canon_off*/