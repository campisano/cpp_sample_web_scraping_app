#include <iostream>
#include <stdexcept>
#include <string>

#include "scraper/infrastructure/config/config_loader.hpp"
#include "scraper/infrastructure/download/download_factory.hpp"
#include "scraper/infrastructure/repository/postgresql/postgresql_factory.hpp"
#include "scraper/infrastructure/schedule/scheduler.hpp"

int main(int, char **)
{
    try
    {
        auto config = ConfigLoader::load("config.json");

        auto repository = PostgresqlFactory::createRepository(
                              config.repository);
        auto ticket_repository = PostgresqlFactory::createTicketRepository(
                                     *repository.get());

        auto downloads = DownloadFactory::create(
                             config.downloads, *ticket_repository);

        Scheduler s;

        while(!downloads.empty())
        {
            auto & d = downloads.front();
            s.add(std::unique_ptr<CommandRecurrence>(
                      new CommandRecurrence
            {
                std::move(d.command), d.interval}));
            downloads.pop_front();
        }

        s.run();
        s.wait();
    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    return 0;
}
