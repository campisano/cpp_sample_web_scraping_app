#ifndef DOWNLOAD_FACTORY__HPP__
#define DOWNLOAD_FACTORY__HPP__

#include <memory>
#include "ticket_downloader.hpp"
#include "../../application/config/download_config.hpp"
#include "../../domain/repositories/ticket_repository.hpp"

class DownloadFactory
{
public:
    explicit DownloadFactory() = delete;

    static std::unique_ptr<TicketDownloader> createTicketDownloader(
        const DownloadConfig & _config, TicketRepository & _repo);
};

#endif
