#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <sstream>

#include "bullet.h"

namespace fs = std::filesystem;

namespace bullet {
namespace parser {
  parser::parser(const int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
      parse(argv[i]);
    }

    flush();
  }

  void parser::parse(const std::string_view& item) {
    item.at(0) == '-' ? flag(item) : value(item);
  }

  void parser::flag(const std::string_view& item) {
    // Strip off flag and keep the word
    flush();
    current_option_ = item;
    current_option_->remove_prefix(current_option_->find_first_not_of('-'));

    // Packed args
    const auto delimiter = current_option_->find_first_not_of('-');
    if (delimiter != std::string_view::npos) {
      auto val = *current_option_;
      val.remove_prefix(delimiter + 1);
      current_option_->remove_suffix(current_option_->size() - delimiter);
      value(val);
    }
  }

  void parser::value(const std::optional<std::string_view>& value) {
    if (!current_option_) {
      positionals_.emplace_back(*value);
    } else {
      optionals_.emplace(*current_option_, value);
      current_option_.reset();
    }
  }

  void parser::flush() {
    if (current_option_) value();
  }

  const option_map& parser::options() const { return optionals_; }

  const std::vector<std::string_view>& parser::positional_arguments() const {
    return positionals_;
  }
} // namespace parser

  void Bullet::check_dir() const {
    const std::string dir = std::string(std::getenv("HOME")) + "/.bullet";

    if (!fs::is_directory(dir) || !fs::exists(dir)) {
      std::cout << "No .bullet dir found, creating" << std::endl;
      fs::create_directory(dir);
    }

    return;
  }

  Note Bullet::new_note() const {
    size_t type;
    std::string note;
    Note n;
    std::cout << "1. deferred\n" <<
              "2. future\n" <<
              "3. task\n" <<
              "4. goal\n" <<
              "5. event\n" <<
              "6. done" << std::endl;
    std::cout << "What type of note is this?";
    std::cin >> type;

    std::cout << "Gimme the goods" << std::endl;
    std::getline(std::cin, note);

    n.note = note;
    n.symbol = default_symbols(type - 1);
    n.id = get_last_id() + 1;

    return n;
  }

  const std::string Bullet::get_current_date() const {
    std::stringstream os;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    os << ltm->tm_year << "-" << ltm->tm_mon << "-" << ltm->tm_mday;

    return os.str();
  }
}// namespace bullet
