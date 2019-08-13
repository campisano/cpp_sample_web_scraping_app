#ifndef HTTP_CONFIG__HPP__
#define HTTP_CONFIG__HPP__

#include <string>

struct HttpConfig
{
    std::string host;
    int port;
    int threads;
};

#endif
