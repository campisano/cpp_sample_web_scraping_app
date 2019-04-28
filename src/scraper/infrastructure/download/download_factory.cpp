#include "download_factory.hpp"

#include "../serialize/parser_factory.hpp"

std::unique_ptr<TicketDownloader>
DownloadFactory::createTicketDownloader(
    const DownloadCfg & _config, TicketRepository & _repo)
{
    return std::unique_ptr<TicketDownloader>(
               new TicketDownloader(
                   _config.URL,
                   ParserFactory::create(_config.parser),
                   _repo));
}
