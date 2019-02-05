#include <bullet/bullet.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace bullet {
  void Bullet::display_menu() {
    const std::string s =
    R"(
    ____        _ _      _     _______ _
   |  _ \      | | |    | |   |__   __(_)
   | |_) |_   _| | | ___| |_     | |   _ _ __ ___   ___
   |  _ <| | | | | |/ _ \ __|    | |  | | '_ ` _ \ / _ \
   | |_) | |_| | | |  __/ |_     | |  | | | | | | |  __/
   |____/ \__,_|_|_|\___|\__|    |_|  |_|_| |_| |_|\___|
    )"
    int option = menu_opt_select();

    switch(option) {
      case 1:
        new_bullet();
        break;
      case 2:
        list_today();
        break;
      case 3:
        list_prev();
        break;
      default:
        std::cout << "That's a weird option, man" << std::endl;
        break;
    }
  }

  int Bullet::menu_opt_select() {
    int opt;
    std::cout << "1) New Entry" << std::endl;
    std::cout << "2) View Bullets For Today" << std::endl;
    std::cout << "3) View Old Notes" << std::endl;
    std::cout << "Whattaya want to do? ";
    std::cin >> opt;

    return std::stoi(opt);
  }

  int Bullet::store_to_system(const Note& note) {
    std::string filename = get_current_date + "bullets.txt";
    std::fstream note_file(filename, std::filestream::app);

    if (!note_file.good()) { throw std::invliad_argument("Invalid path specified"); }

    note_file << note;
    return 0;
  }

  int Bullet::get_last_id() {
    // TODO
  }

  Note Bullet::new_bullet() {
    std::ostream os;
    Note n;
    std::string task_field;
    std::string task_type;
    std::cout << "What would you like to get done? ";
    std::cin >> task_field;
    std::for_each(_config.begin(), _config.end(), [&os](const auto& d) { os << d->second << " " });

    std::cout << std::endl;
    std::cout << "Options: " << os.str() << std::endl;
    std::cout << "What type of task is this? ";
    std::cin >> task_type;

    n.type = task_type;
    n.note = task_field;

    return n;
  }

  /// Parse args as they come in
  int Bullet::parse_opts(int argc, char** argv) {
    if (!argv[1]) {
      display_menu();
      return;
    }

    if (std::string(argv[1]) == "new") {
      new_bullet();
    } else if (std::string(argv[1]) == "list" && !argv[2]) {
      list_today();
    } else if (std::string(argv[1] == "list" && argv[2]) {
      list_prev();
    } else {
      std::cout << "invalid option specified" << std::endl;
      return;
    }
  }

  std::string get_current_date() {
    std::ostream os;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    os << ltm->tm_year << "-" << ltm->tm_mon << "-" << ltm->tm_mday;

    return os.str();
  }
} // namespace bullet
