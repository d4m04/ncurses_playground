/* include ncurses header */
#include <ncurses.h>

int main() {
  /* initialize screen in main function */
  initscr();

  /* print hello world */
  printw("Hello World");

  /* refresh the screen to display changes */
  refresh();

  /* wait for input */
  getch();

  /* clean up and end ncuses mode */
  endwin();

  return 0;
}
