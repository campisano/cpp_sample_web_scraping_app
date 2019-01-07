#ifndef TICKET_REPOSITORY__HPP__
#define TICKET_REPOSITORY__HPP__

#include "../domain/ticket.hpp"
#include "repository.hpp"

class TicketRepository
{
public:
    // explicit TicketRepository(Repository & _repo);
    // virtual ~TicketRepository();

    virtual void insert(const Ticket & _ticket) = 0;
};

#endif
