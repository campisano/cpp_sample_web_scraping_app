#include "postgresql_factory.hpp"

#include <sstream>
#include <stdexcept>

#include "postgresql_repository.hpp"
#include "postgresql_ticket_repository.hpp"

std::unique_ptr<Repository> PostgresqlFactory::createRepository(
    const RepositoryCfg & _config)
{
    if(_config.driver != "postgres")
    {
        std::stringstream msg;
        msg << "Unknown driver specified [" << _config.driver << "]";
        throw std::runtime_error(msg.str());
    }

    return std::unique_ptr<Repository>(new PostgresqlRepository(_config));
}

std::unique_ptr<TicketRepository> PostgresqlFactory::createTicketRepository(
    Repository & _repo)
{
    if(dynamic_cast<PostgresqlRepository *>(&_repo) == nullptr)
    {
        std::stringstream msg;
        msg << "Unknown repository specified ["
            << typeid(_repo).name() << "]" << std::endl;
        throw std::runtime_error(msg.str());
    }

    return std::unique_ptr<TicketRepository>(
               new PostgresqlTicketRepository(
                   static_cast<PostgresqlRepository &>(_repo)));
}
