#include "download_factory.hpp"

#include "ticket_downloader.hpp"
#include "../serialize/parser_factory.hpp"

std::list<CommandRecurrence> DownloadFactory::create(const
        std::vector<DownloadCfg> & _config, TicketRepository & _repo)
{
    std::list<CommandRecurrence> cmd_recs;

    for(const auto & dwn : _config)
    {
        cmd_recs.push_back(CommandRecurrence
        {
            std::unique_ptr<Command>(
                new TicketDownloader(
                    dwn.URL, ParserFactory::create(dwn.parser), _repo)),
            dwn.interval
        });
    }

    return cmd_recs;
}
