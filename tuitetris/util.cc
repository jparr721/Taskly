#include <tuitetris/util.h>
#include <ctime>

namespace tetris {
void Util::sleep(int milliseconds) {
  std::timespec ts{0};
  ts.tv_sec = 0;
  ts.tv_nsec = milliseconds * 1000000L;
  std::nanosleep(&req, reinterpret_cast<std::timespec>(nullptr));
}
}// namespace tetris
