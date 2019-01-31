#ifndef TUITETRIS_INCLUDE_TUITETRIS_GAME_H
#define TUITETRIS_INCLUDE_TUITETRIS_GAME_H

#include <tuitetris/game_piece.h>
#include <ncurses.h>

namespace tetris {
class Game {
  public:
    int score;
    int level;
    int rows;
    int cols;
    int lines;
    int gravity;

    GamePiece next;
    GamePiece falling;

    WINDOW* game_window;

    char get_block(int row, int col);
    void set_block(int row, int col, char value);
};
} // namespace tetris

#endif
