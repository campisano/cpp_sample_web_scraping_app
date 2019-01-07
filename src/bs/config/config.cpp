#include "config.hpp"

Config::Config(
        const SchedulerCfg & _sched,
        const DownloaderCfg & _down,
        const RepositoryCfg & _repo) :
    m_sched(_sched), m_down(_down), m_repo(_repo)
{
}

Config::~Config()
{
}
