#ifndef BULLET_H_
#define BULLET_H_

#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <sstream>
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
    const std::vector<std::string_view>& positional_arguments() const;

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
      struct Note {
        std::string note;
        std::string symbol;
        int id;
        std::string str() {
          std::ostringstream os;

          os << id << " " << symbol << " " << note;

          return os.str();
        }
      };
      Bullet(
          const option_map& optionals,
          const std::vector<std::string_view>& positionals)
        : optionals_(optionals), positionals_(positionals) {};
      void check_dir() const;
      void handle_args();
    private:
      void display_menu() const;
      void write(Note& note);
      void show_usage() const;
      void get_todays_notes();
      void get_previous_notes(const std::string notefile);

      int get_last_id();

      const std::string get_current_date() const;
      const std::string make_source_path(const std::optional<std::string_view>& date = std::nullopt) const;

      const std::vector<std::string> read_file_line_by_line(const std::string& filename) const;

      Note new_note();

      const std::array<std::string, 4> avail_options{{"new", "list", "reset"}};
      const std::array<std::string, 6> default_symbols{{ "<", ">", "*", "^", "o", "x"}};
      option_map optionals_;
      std::vector<std::string_view> positionals_;
  };
} // namespace bullet

#endif // BULLET_H_
