#ifndef CONFIG__HPP__
#define CONFIG__HPP__

#include <vector>
#include "download_config.hpp"
#include "http_config.hpp"
#include "repository_config.hpp"

struct Config
{
    RepositoryConfig repository;
    HttpConfig http;
    std::vector<DownloadConfig> downloads;
};

#endif
