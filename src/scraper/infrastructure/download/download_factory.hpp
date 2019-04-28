#ifndef DOWNLOAD_FACTORY__HPP__
#define DOWNLOAD_FACTORY__HPP__

#include <memory>
#include "ticket_downloader.hpp"
#include "../config/download_cfg.hpp"
#include "../../domain/repositories/ticket_repository.hpp"

class DownloadFactory
{
public:
    explicit DownloadFactory() = delete;

    static std::unique_ptr<TicketDownloader> createTicketDownloader(
        const DownloadCfg & _config, TicketRepository & _repo);
};

#endif
