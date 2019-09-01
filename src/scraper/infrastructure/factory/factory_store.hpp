#ifndef FACTORY_STORE__HPP__
#define FACTORY_STORE__HPP__

#include <map>
#include <memory>
#include <string>

template <typename FACTORY>
class FactoryStore
{
public:
    void put(std::unique_ptr<FACTORY> _factory, std::string _name);
    FACTORY & get(std::string _name);

private:
    std::map<std::string, std::unique_ptr<FACTORY>> m_factories;
};

template <typename FACTORY>
void FactoryStore<FACTORY>::put(
    std::unique_ptr<FACTORY> _factory, std::string _name)
{
    m_factories[_name] = std::move(_factory);
}

template <typename FACTORY>
FACTORY & FactoryStore<FACTORY>::get(std::string _name)
{
    return *(m_factories[_name].get());
}

#endif
