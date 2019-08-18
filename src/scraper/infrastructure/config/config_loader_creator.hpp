#ifndef CONFIG_LOADER_CREATOR__HPP__
#define CONFIG_LOADER_CREATOR__HPP__

#include <map>
#include <memory>
#include <string>
#include "config_loader.hpp"

class ConfigLoaderCreator
{
public:
    void put(
        std::unique_ptr<ConfigLoader> _config_loader,
        std::string _file_extension);
    ConfigLoader & get(std::string _file_extension);

private:
    std::map<std::string, std::unique_ptr<ConfigLoader>> m_loaders;
};

#endif
