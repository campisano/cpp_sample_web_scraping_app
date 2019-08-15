#include "yaml_config_loader.hpp"

#include <yaml-cpp/yaml.h>
#include <string>

Config YamlConfigLoader::load(std::string _filepath)
{
    YAML::Node y = YAML::LoadFile(_filepath);

    RepositoryConfig repo_cfg
    {
        y["repository"]["driver"].as<std::string>(),
        y["repository"]["host"].as<std::string>(),
        y["repository"]["port"].as<int>(),
        y["repository"]["username"].as<std::string>(),
        y["repository"]["password"].as<std::string>(),
        y["repository"]["database"].as<std::string>()
    };

    HttpConfig http_cfg
    {
        y["http"]["host"].as<std::string>(),
        y["http"]["port"].as<int>(),
        y["http"]["threads"].as<int>()
    };

    std::vector<DownloadConfig> down_cfg;
    for(const auto & dwn : y["downloads"])
    {
        down_cfg.push_back(
            DownloadConfig
        {
            dwn["url"].as<std::string>(),
            dwn["interval"].as<int>(),
            dwn["parser"].as<std::string>()});
    }

    return Config{repo_cfg, http_cfg, down_cfg};
}
