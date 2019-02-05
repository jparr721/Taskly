#include <bullet/bullet.h>

int main(int argc, char** argv) {
  bullet::Bullet config;
  bullet::Bullet journal(config.parse_opts());


  return journal.parse_opts(argc, argv);
}
