#include <iostream>
#include <stdexcept>
#include <string>

#include "scraper/application/usecases/get_tickets.hpp"
#include "scraper/infrastructure/config/json_config_loader.hpp"
#include "scraper/infrastructure/config/yaml_config_loader.hpp"
#include "scraper/infrastructure/download/download_factory.hpp"
#include "scraper/infrastructure/factory/factory_store.hpp"
#include "scraper/infrastructure/http/handlers/error_handler.hpp"
#include "scraper/infrastructure/http/handlers/health_handler.hpp"
#include "scraper/infrastructure/http/handlers/ticket_handler.hpp"
#include "scraper/infrastructure/http/http_server.hpp"
#include "scraper/infrastructure/repository/postgresql/postgresql_factory.hpp"
#include "scraper/infrastructure/schedule/scheduler.hpp"

FactoryStore<ConfigLoader> cl_fs;
FactoryStore<RepositoryFactory> rf_fs;

void initFactories();
Config loadConfig(std::string _file_path);
Scheduler startScheduler(
    Config & _config, TicketRepository & _ticket_repository);
HttpServer startHttpServer(
    HttpConfig & _config, TicketRepository & _ticket_repository);

int main(int, char **)
{
    try
    {
        initFactories();

        auto config = loadConfig("resources/config.yaml");

        auto & repository_factory = rf_fs.get(config.repository.driver);
        auto repository_source = repository_factory.createRepositorySource(
                                     config.repository);
        auto ticket_repository = repository_factory.createTicketRepository(
                                     *repository_source.get());

        auto scheduler = startScheduler(config, *ticket_repository);
        auto http_server = startHttpServer(config.http, *ticket_repository);

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

void initFactories()
{
    cl_fs.put(std::unique_ptr<ConfigLoader>(new JsonConfigLoader()), "json");
    cl_fs.put(std::unique_ptr<ConfigLoader>(new YamlConfigLoader()), "yaml");

    rf_fs.put(std::unique_ptr<RepositoryFactory>(
                  new(PostgresqlFactory)), "postgres");
}

Config loadConfig(std::string _file_path)
{
    std::string ext;
    auto idx = _file_path.rfind('.');

    if(idx != std::string::npos && idx != _file_path.length())
    {
        ext = _file_path.substr(idx + 1);
    }

    return cl_fs.get(ext).load(_file_path);
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
    HttpConfig & _config, TicketRepository & _ticket_repository)
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

    http_server.start(_config.host, _config.port, _config.threads);

    return http_server;
}
