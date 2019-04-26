#include <iostream>
#include <stdexcept>
#include <string>

#include "scraper/infrastructure/config/config_loader.hpp"
#include "scraper/infrastructure/repository/postgresql/postgresql_factory.hpp"
#include "scraper/infrastructure/download/download_factory.hpp"
#include "scraper/infrastructure/schedule/scheduler.hpp"

//#include "scraper/infrastructure/rest/hello.hpp"


#include <pistache/endpoint.h>

using namespace Pistache;

struct HelloHandler : public Http::Handler
{
    HTTP_PROTOTYPE(HelloHandler)
    void onRequest(const Http::Request &, Http::ResponseWriter writer) override
    {
        writer.send(Http::Code::Ok, "Hello, World!");
    }
};

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
        Http::listenAndServe<HelloHandler>("*:9080");
        s.wait();
    }
    catch(std::exception const & _ex)
    {
        std::cerr << "Error: " << _ex.what() << std::endl;
        throw;
    }

    return 0;
}
