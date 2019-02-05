#pragma once

#include <string>
#include <unordered_map>

namespace bullet {
  class Config {
    public:
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
