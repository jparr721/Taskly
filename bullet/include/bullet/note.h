#ifndef BULLET_INCLUDE_BULLET_NOTE_H
#define BULLET_INCLUDE_BULLET_NOTE_H

#include <string>
#include <sstream>
#include <unordered_map>

namespace bullet {
  struct Note {
    int id;

    std::string type;
    std::string note;

    std::unordered_map<std::string, std::string> _config;

    Note(std::unordered_map<std::string, std::string> config) : _config(config) {};

    char convert_type();

    friend std::ostream& operator<<(std::ostream& os, Note const& n);
  };
} // namespace bullet

#endif
