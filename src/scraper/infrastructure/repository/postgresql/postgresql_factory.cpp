#include "postgresql_factory.hpp"

#include <sstream>
#include <stdexcept>

#include "postgresql_repository_source.hpp"
#include "postgresql_ticket_repository.hpp"

std::unique_ptr<RepositorySource> PostgresqlFactory::createRepositorySource(
    const RepositoryConfig & _config)
{
    if(_config.driver != "postgres")
    {
        std::stringstream msg;
        msg << "Unknown driver specified [" << _config.driver << "]";
        throw std::runtime_error(msg.str());
    }

    return std::unique_ptr<RepositorySource>(
               new PostgresqlRepositorySource(_config));
}

std::unique_ptr<TicketRepository> PostgresqlFactory::createTicketRepository(
    RepositorySource & _repo_src)
{
    if(dynamic_cast<PostgresqlRepositorySource *>(&_repo_src) == nullptr)
    {
        std::stringstream msg;
        msg << "Unknown repository source specified ["
            << typeid(_repo_src).name() << "]" << std::endl;
        throw std::runtime_error(msg.str());
    }

    return std::unique_ptr<TicketRepository>(
               new PostgresqlTicketRepository(
                   static_cast<PostgresqlRepositorySource &>(_repo_src)));
}
