#ifndef TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H
#define TUITETRIS_INCLUDE_TUITETRIS_SCREEN_H

#include <string>

namespace tetris {
class Screen {
  public:
    void title_screen(std::string message);
    void game_screen();
};
}// namespace tetris

#endif
