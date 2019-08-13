#include "json_config_loader.hpp"

#include <fstream>
#include <json.hpp>
#include <string>

Config JsonConfigLoader::load(std::string _filepath)
{
    std::ifstream config_file(_filepath);
    nlohmann::json j = nlohmann::json::parse(config_file);

    RepositoryConfig repo_cfg
    {
        j["repository"]["driver"].get<std::string>(),
        j["repository"]["host"].get<std::string>(),
        j["repository"]["port"].get<int>(),
        j["repository"]["username"].get<std::string>(),
        j["repository"]["password"].get<std::string>(),
        j["repository"]["database"].get<std::string>()
    };

    HttpConfig http_cfg
    {
        j["http"]["host"].get<std::string>(),
        j["http"]["port"].get<int>(),
        j["http"]["threads"].get<int>()
    };

    std::vector<DownloadConfig> down_cfg;
    for(const auto & dwn : j["downloads"])
    {
        down_cfg.push_back(
            DownloadConfig{dwn["url"], dwn["interval"], dwn["parser"]});
    }

    return Config{repo_cfg, http_cfg, down_cfg};
}
