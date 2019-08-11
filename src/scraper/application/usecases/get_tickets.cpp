#include "get_tickets.hpp"

GetTickets::GetTickets(TicketRepository & _ticket_repository)
    : m_ticket_repository(_ticket_repository)
{
}

GetTickets::~GetTickets()
{
}

std::vector<Ticket> GetTickets::getTickets()
{
    return m_ticket_repository.getAll();
}
