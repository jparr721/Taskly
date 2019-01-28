#include <tuitetris/screen.h>
#include <ncurses.h>

namespace tetris {
void Screen::game_screen() {
  initscr();
  printw("Tetris");
  refresh();
  int character = getch();
  switch(character) {
    case 'Q':
      endwin();
    default:
      printw(reinterpret_cast<const char*>(character));
  }
}
}// namespace tetris
