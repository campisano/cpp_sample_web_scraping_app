#ifndef TICKET_API__HPP__
#define TICKET_API__HPP__

#include <vector>
#include "../aggregates/tickets/ticket.hpp"
#include "../repositories/ticket_repository.hpp"

class TicketAPI
{
public:
    explicit TicketAPI(TicketRepository & _ticket_rep);
    TicketAPI(const TicketAPI &) = delete;
    TicketAPI(TicketAPI &&) = delete;
    virtual ~TicketAPI();

    std::vector<Ticket> getTickets();

private:
    TicketRepository & m_ticket_rep;
};

#endif
