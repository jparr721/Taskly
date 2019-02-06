#include <filesystem>
#include <bullet/util.h>

namespace fs = std::filesystem;

namespace bullet {
  void Util::check_dir(const std::string& path) {
    std::string bullet_dir = _config["BULLET_PATH"];
    std::cout << "validating..." << bullet_dir << std::endl;
    if (!fs::is_directory(bullet_dir) || !fs::exists(bullet_dir)) {
      std::cout << "Dir not found, making" << std::endl;
      fs::create_directory(bullet_dir);
    }
  }
}// namespace bullet
