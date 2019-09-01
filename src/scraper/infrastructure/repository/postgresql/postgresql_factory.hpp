#ifndef POSTGRESQL_FACTORY__HPP__
#define POSTGRESQL_FACTORY__HPP__

#include <memory>
#include "../repository_factory.hpp"

class PostgresqlFactory : public RepositoryFactory
{
public:
    explicit PostgresqlFactory() = default;
    PostgresqlFactory(const PostgresqlFactory &) = delete;
    PostgresqlFactory(PostgresqlFactory &&) = delete;
    virtual ~PostgresqlFactory() = default;

    PostgresqlFactory & operator=(const PostgresqlFactory &) = delete;
    PostgresqlFactory & operator=(PostgresqlFactory &&) = delete;

    std::unique_ptr<RepositorySource> createRepositorySource(
        const RepositoryConfig & _config);

    std::unique_ptr<TicketRepository> createTicketRepository(
        RepositorySource & _repo);
};

#endif
