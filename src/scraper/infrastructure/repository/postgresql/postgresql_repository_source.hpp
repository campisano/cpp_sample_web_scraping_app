#ifndef POSTGRESQL_REPOSITORY_SOURCE__HPP__
#define POSTGRESQL_REPOSITORY_SOURCE__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../repository_source.hpp"
#include "../../../application/config/repository_cfg.hpp"

class PostgresqlRepositorySource : public RepositorySource
{
public:
    explicit PostgresqlRepositorySource(const RepositoryCfg & _config);
    PostgresqlRepositorySource(const PostgresqlRepositorySource &) = delete;
    PostgresqlRepositorySource(PostgresqlRepositorySource &&) = delete;
    virtual ~PostgresqlRepositorySource();

    std::shared_ptr<sqlpp::postgresql::connection> connection();

private:
    struct data;
    data & m_data;
};

#endif
