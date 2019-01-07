#include <iostream>
#include <stdexcept>
#include <string>

#include "bs/config/config_loader.hpp"
#include "bs/downloader/ticket_downloader.hpp"
#include "bs/infra/db.hpp"
#include "bs/scheduler/scheduler.hpp"

int main(/*int _argc, char** _argv*/)
{
    try
    {
        auto config = loadConfig("config.json");

        auto repository = createRepository(config.repository());
        auto ticket_repository = createTicketRepository(*repository.get());

        TicketDownloader td(config.downloader(), *ticket_repository.get());
        Scheduler s(config.scheduler(), (Command &)td);
        s.run();
    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    std::cout << "end" << std::endl;

    return 0;
}
