#ifndef POSTGRESQL_REPOSITORY_SOURCE__HPP__
#define POSTGRESQL_REPOSITORY_SOURCE__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../repository_source.hpp"
#include "../../../application/config/repository_config.hpp"

class PostgresqlRepositorySource : public RepositorySource
{
public:
    explicit PostgresqlRepositorySource(const RepositoryConfig & _config);
    PostgresqlRepositorySource(const PostgresqlRepositorySource &) = delete;
    PostgresqlRepositorySource(PostgresqlRepositorySource &&) = delete;
    virtual ~PostgresqlRepositorySource();

    PostgresqlRepositorySource & operator=(
        const PostgresqlRepositorySource &) = delete;
    PostgresqlRepositorySource & operator=(
        PostgresqlRepositorySource &&) = delete;

public:
    std::shared_ptr<sqlpp::postgresql::connection> connection();

private:
    struct data;
    data & m_data;
};

#endif
