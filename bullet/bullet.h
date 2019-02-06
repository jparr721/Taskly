#ifndef BULLET_H_
#define BULLET_H_

#include <algorithm>
#include <cmath>
#include <optional>
#include <string>
#include <string_view>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace bullet {
  using symbol_map = std::unordered_map<std::string, std::string>;
  using option_map =
    std::unordered_map<std::string_view, std::optional<std::string_view>>;

  struct parser {
    // Heavily adapted from: https://github.com/sailormoon/flags/blob/master/include/flags.h
    const std::array<std::string, 4> avail_options{{"new", "list", "find", "reset"}};

    parser(const int argc, char** argv);

    parser& operator=(const parser&) = delete;

    const option_map& options() const;
    const std:;vector<std::string_view>& positional_arguments() const;

    private:
    void flush();
    void parse(const std::string_view& item);
    void flag(const std::string_view& item);
    void value(const std::optional<std::string_view>& value = std::nullopt);

    std::optional<std::string_view> current_option_;
    std::vector<std::string_view> positionals_;
    option_map optionals_;
  };

  class Bullet {
    public:
      const symbol_map default_symbols{
        {"deferred", "<"},
        {"future", ">"},
        {"today", "*"},
        {"goal", "^"},
        {"event", "o"},
        {"done", "x"},
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
