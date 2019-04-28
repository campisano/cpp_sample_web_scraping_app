#ifndef TICKET_REPOSITORY__HPP__
#define TICKET_REPOSITORY__HPP__

#include "../aggregates/tickets/ticket.hpp"

class TicketRepository
{
public:
    virtual void insert(const Ticket & _ticket) = 0;
};

#endif
