#ifndef REPOSITORY_CFG__HPP__
#define REPOSITORY_CFG__HPP__

#include <string>

class RepositoryCfg
{
public:
    explicit RepositoryCfg(
        std::string _driver,
        std::string _host,
        int _port,
        std::string _username,
        std::string _password,
        std::string _database);
    virtual ~RepositoryCfg();

    std::string driver() const { return m_driver; }
    std::string host() const { return m_host; }
    int port() const { return m_port; }
    std::string username() const { return m_username; }
    std::string password() const { return m_password; }
    std::string database() const { return m_database; }

private:
    std::string m_driver;
    std::string m_host;
    int m_port;
    std::string m_username;
    std::string m_password;
    std::string m_database;
};

#endif
