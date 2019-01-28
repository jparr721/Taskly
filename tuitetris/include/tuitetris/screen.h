#ifndef TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H
#define TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H

#include <string>
#include <memory>
#include <ncurses.h>

namespace tetris {
class Screen {
  public:
    WINDOW* make_screen(int height, int width, int startx, int starty);
    void destroy_window(WINDOW* window);
};
}// namespace tetris

#endif
