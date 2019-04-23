#ifndef POSTGRESQL_REPOSITORY__HPP__
#define POSTGRESQL_REPOSITORY__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../../config/repository_cfg.hpp"
#include "../../../repository/repository.hpp"

class PostgresqlRepository : public Repository
{
public:
    explicit PostgresqlRepository(const RepositoryCfg & _config);
    PostgresqlRepository(const PostgresqlRepository &) = delete;
    PostgresqlRepository(PostgresqlRepository &&) = delete;
    virtual ~PostgresqlRepository();

    std::shared_ptr<sqlpp::postgresql::connection> connection();

private:
    struct data;
    data & m_data;
};

#endif
