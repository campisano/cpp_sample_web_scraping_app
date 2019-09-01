#ifndef POSTGRESQL_SOURCE__HPP__
#define POSTGRESQL_SOURCE__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../repository_source.hpp"
#include "../../../application/config/repository_config.hpp"

class PostgresqlSource : public RepositorySource
{
public:
    explicit PostgresqlSource(const RepositoryConfig & _config);
    PostgresqlSource(const PostgresqlSource &) = delete;
    PostgresqlSource(PostgresqlSource &&) = delete;
    virtual ~PostgresqlSource();

    PostgresqlSource & operator=(const PostgresqlSource &) = delete;
    PostgresqlSource & operator=(PostgresqlSource &&) = delete;

public:
    std::shared_ptr<sqlpp::postgresql::connection> connection();

private:
    struct data;
    data & m_data;
};

#endif
