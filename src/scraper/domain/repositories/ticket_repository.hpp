#ifndef TICKET_REPOSITORY__HPP__
#define TICKET_REPOSITORY__HPP__

#include <vector>
#include "../aggregates/tickets/ticket.hpp"

class TicketRepository
{
public:
    virtual void insert(const Ticket & _ticket) = 0;
    virtual std::vector<Ticket> getAll() = 0;
};

#endif
