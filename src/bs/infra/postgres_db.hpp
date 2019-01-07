#ifndef POSTGRES_DB__HPP__
#define POSTGRES_DB__HPP__

#include <memory>
#include <sqlpp11/postgresql/connection.h>
#include "../repository/repository.hpp"

class PostgresDB : public Repository
{
public:
    explicit PostgresDB(const RepositoryCfg & _config);
    virtual ~PostgresDB();

    sqlpp::postgresql::connection & connection() {
        return m_conn;
    }

private:
    sqlpp::postgresql::connection m_conn;
};

#endif
