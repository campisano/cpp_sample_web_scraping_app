#ifndef POSTGRESQL_FACTORY__HPP__
#define POSTGRESQL_FACTORY__HPP__

#include <memory>
#include "../repository_source.hpp"
#include "../../config/repository_cfg.hpp"
#include "../../../domain/repositories/ticket_repository.hpp"

class PostgresqlFactory
{
public:
    explicit PostgresqlFactory() = delete;

    static std::unique_ptr<RepositorySource> createRepositorySource(
        const RepositoryCfg & _config);

    static std::unique_ptr<TicketRepository> createTicketRepository(
        RepositorySource & _repo);
};

#endif
