#ifndef TICKET_HANDLER__HPP__
#define TICKET_HANDLER__HPP__

#include <memory>
#include <restbed>

#include "../../../application/usecases/get_tickets.hpp"

class TicketHandler
{
public:
    explicit TicketHandler(GetTickets & _get_tickets);
    TicketHandler(const TicketHandler &) = default;
    TicketHandler(TicketHandler &&) = default;
    virtual ~TicketHandler();

    void getTickets(const std::shared_ptr< restbed::Session > _session);

private:
    GetTickets & m_get_tickets;
};

#endif
