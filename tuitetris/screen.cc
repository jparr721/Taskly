#include <tuitetris/screen.h>

namespace tetris {
  WINDOW* Screen::make_screen(int height, int width, int startx, int starty) {
    WINDOW* window;
    window = newwin(height, width, startx, starty);
    box(local_win, 0, 0);

    wrefresh(window);

    return window;
  }

  void destroy_window(WINDOW* window) {
    wborder(window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    /* The parameters taken are
     * 1. win: the window on which to operate
     * 2. ls: character to be used for the left side of the window
     * 3. rs: character to be used for the right side of the window
     * 4. ts: character to be used for the top side of the window
     * 5. bs: character to be used for the bottom side of the window
     * 6. tl: character to be used for the top left corner of the window
     * 7. tr: character to be used for the top right corner of the window
     * 8. bl: character to be used for the bottom left corner of the window
     * 9. br: character to be used for the bottom right corner of the window
     */
    wrefresh(window);
    delwin(window);
  }
}// namespace tetris
