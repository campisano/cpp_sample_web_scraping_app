#include <fstream>
#include <json.hpp>
#include <string>

#include "config_loader.hpp"

Config loadConfig(std::string _filepath)
{
    std::ifstream config_file(_filepath);
    nlohmann::json j = nlohmann::json::parse(config_file);

    return Config{
        SchedulerCfg{j["scheduler"]["interval"].get<int>()},
            DownloaderCfg{j["downloader"]["URL"].get<std::string>()},
                RepositoryCfg{
                    j["repository"]["driver"].get<std::string>(),
                        j["repository"]["host"].get<std::string>(),
                        j["repository"]["port"].get<int>(),
                        j["repository"]["username"].get<std::string>(),
                        j["repository"]["password"].get<std::string>(),
                        j["repository"]["database"].get<std::string>()}
    };
}
