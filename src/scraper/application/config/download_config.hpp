#ifndef DOWNLOAD_CONFIG__HPP__
#define DOWNLOAD_CONFIG__HPP__

#include <string>

struct DownloadConfig
{
    std::string URL;
    long interval;
    std::string parser;
};

#endif
