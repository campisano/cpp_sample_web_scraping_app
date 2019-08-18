#include "config_loader_creator.hpp"

void ConfigLoaderCreator::put(
    std::unique_ptr<ConfigLoader> _config_loader,
    std::string _file_extension)
{
    m_loaders[_file_extension] = std::move(_config_loader);
}

ConfigLoader & ConfigLoaderCreator::get(std::string _file_extension)
{
    return *(m_loaders[_file_extension].get());
}
