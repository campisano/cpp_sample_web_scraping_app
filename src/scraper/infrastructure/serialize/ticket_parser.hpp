#ifndef TICKET_PARSER__HPP__
#define TICKET_PARSER__HPP__

#include <string>
#include "../../domain/aggregates/tickets/ticket.hpp"

class TicketParser
{
public:
    virtual Ticket parse(std::string _data) = 0;
};

#endif
