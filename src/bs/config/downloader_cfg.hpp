#ifndef DOWNLOADER_CFG__HPP__
#define DOWNLOADER_CFG__HPP__

#include <string>

class DownloaderCfg
{
public:
    explicit DownloaderCfg(std::string _URL);
    virtual ~DownloaderCfg();

    std::string URL() const { return m_URL; }

private:
    std::string m_URL;
};

#endif
