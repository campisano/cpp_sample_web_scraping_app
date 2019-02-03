#include <iostream>
#include <stdexcept>
#include <string>

#include "bs/config/config_loader.hpp"
#include "bs/download/download_factory.hpp"
#include "bs/infra/db.hpp"
#include "bs/scheduler/scheduler.hpp"

int main(int, char **)
{
    try
    {
        auto config = ConfigLoader::load("config.json");

        auto repository = createRepository(config.repository);
        auto ticket_repository = createTicketRepository(*repository.get());

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
