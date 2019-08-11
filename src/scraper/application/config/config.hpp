#ifndef CONFIG__HPP__
#define CONFIG__HPP__

#include <vector>
#include "download_cfg.hpp"
#include "repository_cfg.hpp"

struct Config
{
    RepositoryCfg repository;
    std::vector<DownloadCfg> downloads;
};

#endif
