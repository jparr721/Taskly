#ifndef TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H
#define TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H

#include <string>
#include <tuitetris/game_piece.h>
#include <memory>
#include <ncurses.h>

namespace tetris {
class Screen {
  public:
    WINDOW* make_screen(int height, int width, int startx, int starty);
    void destroy_window(WINDOW* window);
    void display_score(WINDOW* w);
    void display_game_piece(WINDOW* w, const GamePiece g);
};
}// namespace tetris

#endif
