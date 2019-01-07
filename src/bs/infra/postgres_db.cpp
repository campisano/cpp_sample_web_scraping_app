#include "postgres_db.hpp"

#include <sqlpp11/postgresql/exception.h>
#include <sqlpp11/sqlpp11.h>

PostgresDB::PostgresDB(const RepositoryCfg & _config)
{
    auto config = std::make_shared<sqlpp::postgresql::connection_config>();
    config->host = _config.host();
    config->user = _config.username();
    config->password = _config.password();
    config->dbname = _config.database();

    m_conn.connectUsing(config);
}

PostgresDB::~PostgresDB()
{
}
