#include <iostream>
#include <stdexcept>
#include <string>

#include "scraper/domain/api/ticket_api.hpp"
#include "scraper/infrastructure/config/json_config_loader.hpp"
#include "scraper/infrastructure/download/download_factory.hpp"
#include "scraper/infrastructure/http/handlers/error_handler.hpp"
#include "scraper/infrastructure/http/handlers/health_handler.hpp"
#include "scraper/infrastructure/http/handlers/ticket_handler.hpp"
#include "scraper/infrastructure/http/http_server.hpp"
#include "scraper/infrastructure/repository/postgresql/postgresql_factory.hpp"
#include "scraper/infrastructure/schedule/scheduler.hpp"

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

        std::list<CommandRecurrence> downloads;

        for(const auto & dwn : config.downloads)
        {
            downloads.push_back(CommandRecurrence
            {
                std::unique_ptr<Command>(
                    DownloadFactory::createTicketDownloader(
                        dwn,
                        *ticket_repository)),
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

        ErrorHandler eh;
        HealthHandler hh;
        TicketAPI ticket_api(*ticket_repository);
        TicketHandler th(ticket_api);

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

        scheduler.wait();
        http_server.wait();

        return EXIT_SUCCESS;

    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    return 0;
}
