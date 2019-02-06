#ifndef BULLET_H_
#define BULLET_H_

#include <array>
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
namespace parser {

  struct parser {
    // Heavily adapted from: https://github.com/sailormoon/flags/blob/master/include/flags.h
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
} // namespace parser

  class Bullet {
    public:
      Bullet(
          const option_map& optionals,
          const std::vector<std::string_view>& positionals)
        : optionals_(optionals), positionals_(positionals) {};

      const std::string get_current_date() const;

      const std::array<std::string, 6> default_symbols{{ "<", ">", "*", "^", "o", "x"}};
    private:
      struct Note {
        std::string note;
        std::string symbol;
        int id;
      };

      void display_menu() const;
      void check_dir() const;
      void write(const Note& note);

      int get_last_id();

      Note new_note() const;

      const std::array<std::string, 4> avail_options{{"new", "list", "find", "reset"}};
      option_map optionals_;
      std::vector<std::string_view> positionals_;
  };
} // namespace bullet

#endif // BULLET_H_
