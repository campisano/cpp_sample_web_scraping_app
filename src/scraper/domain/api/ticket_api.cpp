#include "ticket_api.hpp"

TicketAPI::TicketAPI(TicketRepository & _ticket_rep)
    : m_ticket_rep(_ticket_rep)
{
}

TicketAPI::~TicketAPI()
{
}

std::vector<Ticket> TicketAPI::getTickets()
{
    return m_ticket_rep.getAll();
}
