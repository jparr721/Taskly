#include <cstdlib>
#include <bullet/bullet.h>
#include <bullet/config.h>

int main(int argc, char** argv) {
  const std::string home = std::getenv("HOME");
  const std::string default_config_path = home+"/.bullet";
  bullet::Config config;
  bullet::Bullet journal(config.parse_config(config_path));


  return journal.parse_opts(argc, argv);
}
