#ifndef TUITETRIS_INCLUDE_TUITETRIS_GAME_H
#define TUITETRIS_INCLUDE_TUITETRIS_GAME_H

#include <tuitetris/game_piece.h>

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
};
} // namespace tetris

#endif
