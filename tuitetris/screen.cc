#include <tuitetris/screen.h>

namespace tetris {
  WINDOW* Screen::make_screen(int height, int width, int startx, int starty) {
    WINDOW* window;
    window = newwin(height, width, startx, starty);
    box(window, 0, 0);

    wrefresh(window);

    return window;
  }

  void make_game_board(WINDOW* w, const Game& game) {
    box(w, 0, 0);
    for (int i = 0; i < game.rows; ++i) {
      wmove(w, i + 1, 1);
      for (int j = 0; j < game.cols; ++j) {
        if (cell_empty(game.get_block(i, j))) {
          // add block
        }
      }
    }
  }

  void Screen::destroy_window(WINDOW* window) {
    wborder(window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(window);
    delwin(window);
  }

  void Screen::display_score(WINDOW* w, const Game& game) {
    wclear(w);
    box(w, 0, 0);
    wprintw(w, "Score\n%d\n", game.score);
    wprintw(w, "Level\n%d\n", game.level);
    wprintw(w, "Lines\n%d\n", game.lines);
    wnouterefresh(w);
  }

  void Screen::panic() {
    clear();
    printw("TuiTetris   ls -al   git:master*\n"
            "total 36\n"
            "drwxr-xr-x  6 ghost ghost 4096 Jan 28 14:47 .\n"
            "drwxr-xr-x 10 ghost ghost 4096 Jan 28 12:30 ..\n"
            "drwxr-xr-x  3 ghost ghost 4096 Jan 28 12:55 build\n"
            "drwxr-xr-x  4 ghost ghost 4096 Jan 28 12:53 CMakeFiles\n"
            "-rw-r--r--  1 ghost ghost  645 Jan 28 12:54 CMakeLists.txt\n"
            "drwxr-xr-x  8 ghost ghost 4096 Jan 30 23:17 .git\n"
            "-rw-r--r--  1 ghost ghost   19 Jan 28 12:56 .gitignore\n"
            "-rw-r--r--  1 ghost ghost  224 Jan 28 14:47 README.md\n"
            "drwxr-xr-x  3 ghost ghost 4096 Jan 30 23:16 tuitetris\n"
            "\n");
    echo();
    timeout(-1);
    while (getch() != KEY_F(1));
    timeout(0);
    noecho();
    clear();
  }

  bool Screen::cell_filled(char cell_value) {
    return !cell_value
  }
}// namespace tetris
