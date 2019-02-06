#include <fstream>
#include <iostream>
#include <stdexcept>

#include <bullet/bullet.h>
#include <bullet/config.h>

namespace bullet {
  /// Reset the config
  void Config::reset() {
    const std::string bullet_path = DEFAULTS.at("BULLET_PATH");

    std::ofstream config(bullet_path + "/config");
    if (!config.good()) { throw std::invalid_argument("Invalid path specified inside of reset()"); }
    for(const auto& v : DEFAULTS) {
      config << v.first << ": " << v.second;
    }

    config.close();
  }

  std::unordered_map<std::string, std::string> Config::parse_config(const std::string& config_path) {
    std::cout << "Opening file located in: " << config_path << std::endl;
    std::ifstream config(config_path);

    if (!config.good()) { throw std::invalid_argument("Invalid path specified inside of parse_config()"); }
    std::unordered_map<std::string, std::string> config_data;
    std::string line;
    std::string delimeter = ":";
    std::string key;
    std::string value;

    while (std::getline(config, line)) {
      key = line.substr(0, line.find(delimeter));
      value = line.substr(line.find(delimeter) + 1);

      config_data[key] = value;
    }

    return config_data;
  }
} //namespace bullet
