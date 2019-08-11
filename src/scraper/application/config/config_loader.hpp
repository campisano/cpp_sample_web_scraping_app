#ifndef CONFIG_LOADER__HPP__
#define CONFIG_LOADER__HPP__

#include <string>
#include "config.hpp"

class ConfigLoader
{
public:
    virtual Config load(std::string _file_path) = 0;
};

#endif
