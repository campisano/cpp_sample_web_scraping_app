#include "config_loader.hpp"

#include <fstream>
#include <json.hpp>
#include <string>

Config ConfigLoader::load(std::string _filepath)
{
    std::ifstream config_file(_filepath);
    nlohmann::json j = nlohmann::json::parse(config_file);

    RepositoryCfg repo_cfg
    {
        j["repository"]["driver"].get<std::string>(),
        j["repository"]["host"].get<std::string>(),
        j["repository"]["port"].get<int>(),
        j["repository"]["username"].get<std::string>(),
        j["repository"]["password"].get<std::string>(),
        j["repository"]["database"].get<std::string>()
    };

    std::vector<DownloadCfg> down_cfg;
    for(const auto & dwn : j["downloads"])
    {
        down_cfg.push_back(DownloadCfg{dwn["URL"], dwn["interval"], dwn["parser"]});
    }

    return Config{repo_cfg, down_cfg};
}
