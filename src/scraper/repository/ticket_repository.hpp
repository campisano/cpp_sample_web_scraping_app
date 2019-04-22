#ifndef TICKET_REPOSITORY__HPP__
#define TICKET_REPOSITORY__HPP__

#include "repository.hpp"
#include "../domain/ticket.hpp"

class TicketRepository : public Repository
{
public:
    virtual void insert(const Ticket & _ticket) = 0;
};

#endif
