#ifndef REPOSITORY_FACTORY__HPP__
#define REPOSITORY_FACTORY__HPP__

#include <memory>
#include "repository_source.hpp"
#include "../../application/config/repository_config.hpp"
#include "../../domain/repositories/ticket_repository.hpp"

class RepositoryFactory
{
public:
    virtual ~RepositoryFactory() = default;

    virtual std::unique_ptr<RepositorySource> createRepositorySource(
        const RepositoryConfig & _config) = 0;

    virtual std::unique_ptr<TicketRepository> createTicketRepository(
        RepositorySource & _repo) = 0;
};

#endif
