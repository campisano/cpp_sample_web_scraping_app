#include "ticket_downloader.hpp"

#include <iostream>
#include <cpr/cpr.h>
#include "../domain/ticket.hpp"

TicketDownloader::TicketDownloader(
    std::string _URL,
    std::unique_ptr<TicketParser> _parser,
    TicketRepository & _repo)
    : m_URL(_URL), m_parser(std::move(_parser)), m_repo(_repo)
{
}

TicketDownloader::~TicketDownloader()
{
}

void TicketDownloader::execute()
{
    std::cout << "TicketDownloader::execute()" << std::endl;
    auto request = cpr::Get(cpr::Url{m_URL});
    std::cout << request.status_code << std::endl;
    std::cout << request.header["content-type"] << std::endl;
    std::cout << request.text << std::endl;

    Ticket t = m_parser->parse(request.text);
    m_repo.insert(t);
}
