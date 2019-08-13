#ifndef REPOSITORY_CONFIG__HPP__
#define REPOSITORY_CONFIG__HPP__

#include <string>

struct RepositoryConfig
{
    std::string driver;
    std::string host;
    int port;
    std::string username;
    std::string password;
    std::string database;
};

#endif
