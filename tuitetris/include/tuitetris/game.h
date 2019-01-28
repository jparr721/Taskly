#ifndef TUITETRIS_INCLUDE_TUITETRIS_GAME_H
#define TUITETRIS_INCLUDE_TUITETRIS_GAME_H

namespace tetris {
class Game {
  public:
    int score;
    int level;
    int lines;
    int start();
};
} // namespace tetris

#endif
