#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include <fstream>

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
      val.remove_prefix(delimiter);
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
  }

  void Bullet::show_usage() const {
    const std::string help =
     "Bullet v1.0 - The Terminal Task Tracker!\n"
     "  bullet new              - Make a new bullet\n"
     "  bullet list             - List today's bullets\n"
     "  bullet list <FILE_NAMe> - List any previous bullets file (fmt. YYYY-MM-DD)\n";

    std::cout << help << std::endl;
  }

  void Bullet::handle_args() {
    bool invalid =
      std::any_of(positionals_.begin(), positionals_.end(), [this](const auto& positional) {
        return std::find(avail_options.begin(), avail_options.end(), positional) == avail_options.end();
      });
    if (invalid) {
      std::cerr << "Invalid option detected!" << std::endl;
      show_usage();
    }
    const auto first = positionals_[0];
    const auto second = positionals_[1];

    if (first == "new") {
      // Discard other opts, go into new note func
      new_note();
    }

    if (first == "list") {
      if (!second.empty()) {
        get_previous_notes(make_source_path(second));
      } else {
        get_todays_notes();
      }
    }
  }

  void Bullet::get_todays_notes() {}

  void Bullet::get_previous_notes(const std::string notefile) {}

  void Bullet::write(Note& note) {
    const std::string note_path = make_source_path();
    std::ofstream notefile(note_path, std::ios_base::app);
    notefile << note.str();
  }

  int Bullet::get_last_id() {
    /* const std::vector<std::string> journal_lines = read_file_line_by_line( */
    return 1;
  }

  Bullet::Note Bullet::new_note() {
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
    n.symbol = default_symbols[type - 1];
    n.id = get_last_id() + 1;

    return n;
  }

  const std::string Bullet::make_source_path(const std::optional<std::string_view>& date) const {
    return date ? get_current_date() + "-notes" : std::string(*date) + "-notes";
  }

  const std::string Bullet::get_current_date() const {
    std::stringstream os;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    os << ltm->tm_year << "-" << ltm->tm_mon << "-" << ltm->tm_mday;

    return os.str();
  }

  const std::vector<std::string> Bullet::read_file_line_by_line(const std::string& filename) const {
    std::ifstream input(filename);
    std::vector<std::string> lines;
    if (!input.good()) throw std::invalid_argument("Invalid path specified");

    std::string line;
    while (std::getline(input, line)) {
      std::istringstream iss(line);
      lines.push_back(std::string(iss.str()));
    }

    return lines;
  }
} // namespace bullet

int main(int argc, char** argv) {
  bullet::parser::parser p(argc, argv);
  bullet::Bullet bullet(p.options(), p.positional_arguments());
  bullet.handle_args();
  bullet.check_dir();
  return EXIT_SUCCESS;
}
