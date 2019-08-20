#ifndef GET_TICKETS__HPP__
#define GET_TICKETS__HPP__

#include <vector>
#include "../../domain/aggregates/tickets/ticket.hpp"
#include "../../domain/repositories/ticket_repository.hpp"

class GetTickets
{
public:
    explicit GetTickets(TicketRepository & _ticket_repository);
    GetTickets(const GetTickets &) = delete;
    GetTickets(GetTickets &&) = delete;
    virtual ~GetTickets();

    TicketRepository & operator=(const TicketRepository &) = delete;
    TicketRepository & operator=(TicketRepository &&) = delete;

public:
    std::vector<Ticket> getTickets();

private:
    TicketRepository & m_ticket_repository;
};

#endif
