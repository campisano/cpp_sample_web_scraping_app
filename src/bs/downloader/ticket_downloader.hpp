#ifndef TICKET_DOWNLOADER__HPP__
#define TICKET_DOWNLOADER__HPP__

#include "../scheduler/command.hpp"
#include "../config/downloader_cfg.hpp"
#include "../domain/ticket.hpp"
#include "../repository/ticket_repository.hpp"

class TicketDownloader : public Command
{
public:
  explicit TicketDownloader(const DownloaderCfg & _config, TicketRepository & _repo);
  virtual ~TicketDownloader();

  virtual void execute();

private:
  DownloaderCfg m_config;
  TicketRepository & m_repo;
};

#endif
