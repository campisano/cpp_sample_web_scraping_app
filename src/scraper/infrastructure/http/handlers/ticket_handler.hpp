#ifndef TICKET_HANDLER__HPP__
#define TICKET_HANDLER__HPP__

#include <memory>
#include <restbed>

#include "../../../domain/api/ticket_api.hpp"

class TicketHandler
{
public:
    explicit TicketHandler(TicketAPI & _ticket_api);
    TicketHandler(const TicketHandler &) = default;
    TicketHandler(TicketHandler &&) = default;
    virtual ~TicketHandler();

    void getTickets(const std::shared_ptr< restbed::Session > _session);

private:
    TicketAPI & m_ticket_api;
};

#endif
