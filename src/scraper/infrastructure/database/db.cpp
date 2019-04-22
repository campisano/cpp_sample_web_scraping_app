#include "db.hpp"

#include <sstream>
#include <stdexcept>

#include "postgres_db.hpp"
#include "postgres_ticket_repository.hpp"

std::unique_ptr<Repository> createRepository(const RepositoryCfg & _config)
{
    if(_config.driver == "postgres")
    {
        return std::unique_ptr<Repository>(new PostgresDB(_config));
    }

    std::stringstream msg;
    msg << "Unknown driver specified [" << _config.driver << "]";
    throw std::runtime_error(msg.str());
}

std::unique_ptr<TicketRepository> createTicketRepository(Repository & _repo)
{
    if(dynamic_cast<PostgresDB *>(&_repo) != nullptr)
    {
        return std::unique_ptr<TicketRepository>(
                   new PostgresTicketRepository(
                       static_cast<PostgresDB &>(_repo)));
    }

    std::stringstream msg;
    msg << "Unknown repository specified ["
        << typeid(_repo).name() << "]" << std::endl;
    throw std::runtime_error(msg.str());
}
