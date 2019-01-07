#include "ticket_downloader.hpp"

#include <iostream>
#include <cpr/cpr.h>
#include "../serializer/ticket_serializer.hpp"

TicketDownloader::TicketDownloader(const DownloaderCfg & _config, TicketRepository & _repo)
  : m_config(_config), m_repo(_repo)
{
}

TicketDownloader::~TicketDownloader()
{
}

void TicketDownloader::execute()
{
  std::cout << "TicketDownloader::execute()" << std::endl;
  auto request = cpr::Get(cpr::Url{m_config.URL()});
  std::cout << request.status_code << std::endl;
  std::cout << request.header["content-type"] << std::endl;
  std::cout << request.text << std::endl;

  nlohmann::json js = nlohmann::json::parse(request.text);
  Ticket t = js.get<Ticket>();
  nlohmann::json js2 = t;
  std::cout << js2.dump() << std::endl;
  m_repo.insert(t);
}
