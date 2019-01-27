#ifndef TICKET_DOWNLOADER__HPP__
#define TICKET_DOWNLOADER__HPP__

#include <memory>
#include <string>
#include "../scheduler/command.hpp"
#include "../serializer/ticket_parser.hpp"
#include "../repository/ticket_repository.hpp"

class TicketDownloader : public Command
{
public:
    explicit TicketDownloader(
        std::string _URL,
        std::unique_ptr<TicketParser> _parser,
        TicketRepository & _repo);
    TicketDownloader(const TicketDownloader &) = delete;
    TicketDownloader(TicketDownloader &&) = delete;
    virtual ~TicketDownloader();

    virtual void execute();

private:
    std::string m_URL;
    std::unique_ptr<TicketParser> m_parser;
    TicketRepository & m_repo;
};

#endif
