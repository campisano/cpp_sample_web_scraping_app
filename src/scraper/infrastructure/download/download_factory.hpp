#ifndef DOWNLOAD_FACTORY__HPP__
#define DOWNLOAD_FACTORY__HPP__

#include <list>
#include <vector>
#include "../config/download_cfg.hpp"
#include "../schedule/command_recurrence.hpp"
#include "../../domain/repositories/ticket_repository.hpp"

class DownloadFactory
{
public:
    explicit DownloadFactory() = delete;

    static std::list<CommandRecurrence> create(
        const std::vector<DownloadCfg> & _config, TicketRepository & _repo);
};

#endif
