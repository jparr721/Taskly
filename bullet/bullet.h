#ifndef BULLET_H_
#define BULLET_H_

#include <cmath>
#include <string>
#include <iostream>
#include <unordered_map>

namespace bullet {
  using symbol_map = std::unordered_map<std::string, std::string>;

  struct parser {
    parser(const int argc, char** argv);

  };

  class Bullet {
    public:
      constexpr std::array<std::string, 6> default_symbols = {
        {">", "<", "*", "^", "o", "x" }
      };

      int get_last_id(const std::string& journal);


      std::string get_current_date();
    private:
      struct Note {
        std::string note;
        std::string symbol;
        int id;
      };

      void display_menu();
      void write(const Note& note);
  };
} // namespace bullet

#endif // BULLET_H_
