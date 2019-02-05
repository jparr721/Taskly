#include <bullet/bullet.h>
#include <bullet/config.h>

int main(int argc, char** argv) {
  bullet::Config config;
  bullet::Bullet journal(config.parse_opts());


  return journal.parse_opts(argc, argv);
}
