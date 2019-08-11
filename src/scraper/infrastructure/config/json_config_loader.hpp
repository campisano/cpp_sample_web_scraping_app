#ifndef JSON_CONFIG_LOADER__HPP__
#define JSON_CONFIG_LOADER__HPP__

#include <string>
#include "../../application/config/config_loader.hpp"

class JsonConfigLoader : public ConfigLoader
{
public:
    virtual Config load(std::string _file_path);
};

#endif
