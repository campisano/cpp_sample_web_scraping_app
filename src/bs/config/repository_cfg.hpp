#ifndef REPOSITORY_CFG__HPP__
#define REPOSITORY_CFG__HPP__

#include <string>

struct RepositoryCfg
{
    std::string driver;
    std::string host;
    int port;
    std::string username;
    std::string password;
    std::string database;
};

#endif
