#ifndef DB__HPP__
#define DB__HPP__

#include <memory>
#include "../repository/repository.hpp"
#include "../repository/ticket_repository.hpp"

std::unique_ptr<Repository> createRepository(const RepositoryCfg & _config);
std::unique_ptr<TicketRepository> createTicketRepository(Repository & _repo);

#endif
