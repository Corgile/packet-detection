//
// Created by gzhuadmin on 23-5-12.
//

#ifndef LIVE_CAPTURE_CONFIG_LOADER_HPP
#define LIVE_CAPTURE_CONFIG_LOADER_HPP

#include <unordered_map>
#include <string>
#include "io/daily_logger.hpp"

class ConfigLoader {
private:
  std::unordered_map<std::string, std::string> m_configs;

  void check_config(const std::string& key);

  std::shared_ptr<DailyLogger> logger = DailyLogger::getInstance();

public:
  explicit ConfigLoader(const std::string& config_file_path);

  std::unordered_map<std::string, std::string> get_conf();
};

#endif //LIVE_CAPTURE_CONFIG_LOADER_HPP
