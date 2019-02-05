#pragma once

#include <string>
#include <sstream>
#include <unordered_map>

namespace bullet {
  struct Note {
    enum class BulletType {
      deferred,
      today,
      future,
      goal,
      event
    };

    Note() = default;
    ~Note() = default;
    int id;

    std::string type;
    std::string note;

    std::unordered_map<std::string, std::string> _config;

    Note(std::unordered_map<std::string, std::string> config) : _config(config) {};

    std::string convert_type(const BulletType& t);

    friend std::ostream& operator<<(std::ostream& os, Note const& n);
  };
} // namespace bullet
