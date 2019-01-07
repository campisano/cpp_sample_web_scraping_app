#include "repository_cfg.hpp"

RepositoryCfg::RepositoryCfg(
    std::string _driver,
    std::string _host,
    int _port,
    std::string _username,
    std::string _password,
    std::string _database) :
    m_driver(_driver), m_host(_host), m_port(_port),
    m_username(_username), m_password(_password), m_database(_database)
{
}

RepositoryCfg::~RepositoryCfg()
{
}
