#ifndef TUITETRIS_INCLUDE_TUITETRIS_GAME_PIECE_H
#define TUITETRIS_INCLUDE_TUITETRIS_GAME_PIECE_H

#include <utility>

namespace tetris {
struct GamePiece {
  int type;
  int orientation;
  // (x, y) coordinates
  std::pair<int, int> location;
};
}// namespace tetris

#endif
