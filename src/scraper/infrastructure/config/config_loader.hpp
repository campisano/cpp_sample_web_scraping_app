#ifndef CONFIG_LOADER__HPP__
#define CONFIG_LOADER__HPP__

#include <string>
#include "config.hpp"

class ConfigLoader
{
public:
    explicit ConfigLoader() = delete;

    static Config load(std::string _file_path);
};

#endif
