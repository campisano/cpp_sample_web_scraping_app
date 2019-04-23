#include "postgresql_repository.hpp"

#include <mutex>
#include <recycle/shared_pool.hpp>
#include <sqlpp11/postgresql/exception.h>
#include <sqlpp11/sqlpp11.h>
#include <thread>

struct PostgresqlRepository::data
{
    struct lock_policy
    {
        using mutex_type = std::mutex;
        using lock_type = std::lock_guard<mutex_type>;
    };

    using Conn = sqlpp::postgresql::connection;
    using Config = std::shared_ptr<sqlpp::postgresql::connection_config>;
    using Pool = recycle::shared_pool<Conn, lock_policy>;

    data()
    {
        auto make = [this]()->std::shared_ptr<Conn>
        {
            auto conn = std::make_shared<Conn>();
            conn->connectUsing(config);
            return conn;
        };

        auto recycle = [](std::shared_ptr<Conn>)
        {
        };

        pool = new Pool(make, recycle);
    }

    ~data()
    {
        delete pool;
    }

    Pool * pool;
    Config config;
};

PostgresqlRepository::PostgresqlRepository(
    const RepositoryCfg & _config) : m_data(*new data())
{
    m_data.config = std::make_shared<sqlpp::postgresql::connection_config>();
    m_data.config->host = _config.host;
    m_data.config->user = _config.username;
    m_data.config->password = _config.password;
    m_data.config->dbname = _config.database;
}

PostgresqlRepository::~PostgresqlRepository()
{
    delete & m_data;
}

std::shared_ptr<sqlpp::postgresql::connection>
PostgresqlRepository::connection()
{
    return m_data.pool->allocate();
}
