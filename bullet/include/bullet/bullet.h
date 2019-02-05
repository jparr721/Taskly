#ifndef BULLET_INCLUDE_BULLET_BULLET_H
#define BULLET_INCLUDE_BULLET_BULLET_H

#include <string>
#include <unordered_map>
#include <vector>
#include <bullet/note.h>
#include <bullet/config.h>

namespace bullet {
  class Bullet {
    public:
      std::unordered_map<std::string, std::string> _config;

      Bullet(std::unordered_map<std::string, std::string config) : _config(config) {};

      std::string get_current_date();

      int get_last_id(const std::string& file);
      int parse_opts(int argc, char** argv);
      int menu_opt_select();
      int delete_bullet();

      void list_prev(const std::string date);
      void list_today();

      Note new_bullet();

      void display_menu();

    private:
      int store_to_system();
      int check_dir();
  };
} // namespace bullet

#endif
