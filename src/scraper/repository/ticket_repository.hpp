#ifndef TICKET_REPOSITORY__HPP__
#define TICKET_REPOSITORY__HPP__

#include "../domain/ticket.hpp"

class TicketRepository
{
public:
    virtual void insert(const Ticket & _ticket) = 0;
};

#endif
