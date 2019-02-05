#ifndef BULLET_INCLUDE_BULLET_BULLET_H
#define BULLET_INCLUDE_BULLET_BULLET_H

#include <string>
#include <unordered_map>

namespace bullet {
  enum class BulletType { deferred, today, future, goal, event };

  class Config {
    const std::unordered_map<std::string, std::string> DEFAULTS = {
      { "BULLET_PATH", "~/.bullet" },
      { "DEFERRED_SYMBOL", "<" },
      { "TODAY_SYMBOL", "*" },
      { "FUTURE_SYMBOL", ">" },
      { "GOAL_SYMBOL", "^" },
      { "EVENT_SYMBOL", "o" },
      { "DONE_SYMBOL", "x" },
    };

    void reset();
    std::unordered_map<std::string, std::string> parse_config(const std::string& config_path="~/.bullet/config");
  };
} // namespace bullet

#endif
