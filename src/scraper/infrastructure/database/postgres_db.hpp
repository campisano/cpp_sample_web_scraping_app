#ifndef POSTGRES_DB__HPP__
#define POSTGRES_DB__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../config/repository_cfg.hpp"
#include "../../repository/repository.hpp"

class PostgresDB : public Repository
{
public:
    explicit PostgresDB(const RepositoryCfg & _config);
    PostgresDB(const PostgresDB &) = delete;
    PostgresDB(PostgresDB &&) = delete;
    virtual ~PostgresDB();

    std::shared_ptr<sqlpp::postgresql::connection> connection();

private:
    struct data;
    data & m_data;
};

#endif
