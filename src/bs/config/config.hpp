#ifndef CONFIG__HPP__
#define CONFIG__HPP__

#include "scheduler_cfg.hpp"
#include "downloader_cfg.hpp"
#include "repository_cfg.hpp"

class Config
{
public:
    explicit Config(
        const SchedulerCfg & _sched,
        const DownloaderCfg & _down,
        const RepositoryCfg & _repo);
    virtual ~Config();

    const SchedulerCfg & scheduler() const { return m_sched; }
    const DownloaderCfg & downloader() const { return m_down; }
    const RepositoryCfg & repository() const { return m_repo; }

private:
    SchedulerCfg m_sched;
    DownloaderCfg m_down;
    RepositoryCfg m_repo;
};

#endif
