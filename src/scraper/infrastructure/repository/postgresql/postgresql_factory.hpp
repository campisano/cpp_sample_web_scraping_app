#ifndef POSTGRESQL_FACTORY__HPP__
#define POSTGRESQL_FACTORY__HPP__

#include <memory>
#include "../repository_source.hpp"
#include "../../../application/config/repository_config.hpp"
#include "../../../domain/repositories/ticket_repository.hpp"

class PostgresqlFactory
{
public:
    explicit PostgresqlFactory() = delete;

    static std::unique_ptr<RepositorySource> createRepositorySource(
        const RepositoryConfig & _config);

    static std::unique_ptr<TicketRepository> createTicketRepository(
        RepositorySource & _repo);
};

#endif
