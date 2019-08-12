#include <iostream>
#include <stdexcept>
#include <string>

#include "scraper/application/usecases/get_tickets.hpp"
#include "scraper/infrastructure/config/json_config_loader.hpp"
#include "scraper/infrastructure/download/download_factory.hpp"
#include "scraper/infrastructure/http/handlers/error_handler.hpp"
#include "scraper/infrastructure/http/handlers/health_handler.hpp"
#include "scraper/infrastructure/http/handlers/ticket_handler.hpp"
#include "scraper/infrastructure/http/http_server.hpp"
#include "scraper/infrastructure/repository/postgresql/postgresql_factory.hpp"
#include "scraper/infrastructure/schedule/scheduler.hpp"

Scheduler startScheduler(
    Config & _config, TicketRepository & _ticket_repository);
HttpServer startHttpServer(
    Config & _config, TicketRepository & _ticket_repository);

int main(int, char **)
{
    try
    {
        auto config_loader = std::unique_ptr<JsonConfigLoader>(
                                 new JsonConfigLoader());
        auto config = config_loader->load("resources/config.json");

        auto repository = PostgresqlFactory::createRepositorySource(
                              config.repository);
        auto ticket_repository = PostgresqlFactory::createTicketRepository(
                                     *repository.get());

        auto scheduler = startScheduler(config, *ticket_repository);
        auto http_server = startHttpServer(config, *ticket_repository);

        scheduler.wait();
        http_server.wait();
    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    return EXIT_SUCCESS;
}

Scheduler startScheduler(
    Config & _config, TicketRepository & _ticket_repository)
{
    std::list<CommandRecurrence> downloads;

    for(const auto & dwn : _config.downloads)
    {
        downloads.push_back(CommandRecurrence
        {
            std::unique_ptr<Command>(
                DownloadFactory::createTicketDownloader(
                    dwn,
                    _ticket_repository)),
            dwn.interval
        });
    }

    Scheduler scheduler;

    while(!downloads.empty())
    {
        auto & d = downloads.front();
        scheduler.add(std::unique_ptr<CommandRecurrence>(
                          new CommandRecurrence
        {
            std::move(d.command), d.interval}));
        downloads.pop_front();
    }

    scheduler.start();

    return scheduler;
}

HttpServer startHttpServer(
    Config & _config, TicketRepository & _ticket_repository)
{
    ErrorHandler eh;
    HealthHandler hh;
    GetTickets get_tickets(_ticket_repository);
    TicketHandler th(get_tickets);

    HttpServer http_server;
    http_server.notFound(
        std::bind(&ErrorHandler::notFound, eh, std::placeholders::_1));
    http_server.route(
        "/health", "GET",
        std::bind(&HealthHandler::handle, hh, std::placeholders::_1));
    http_server.route(
        "/tickets", "GET",
        std::bind(&TicketHandler::getTickets, th, std::placeholders::_1));

    http_server.start("127.0.0.1", 8080, 2);

    return http_server;
}
