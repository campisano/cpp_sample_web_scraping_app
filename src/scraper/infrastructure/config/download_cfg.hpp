#ifndef DOWNLOAD_CFG__HPP__
#define DOWNLOAD_CFG__HPP__

#include <string>

struct DownloadCfg
{
    std::string URL;
    long interval;
    std::string parser;
};

#endif
