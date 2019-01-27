#ifndef BITSTAMP_TICKET_PARSER__HPP__
#define BITSTAMP_TICKET_PARSER__HPP__

#include "ticket_parser.hpp"

class BitstampTicketParser : public  TicketParser
{
public:
    explicit BitstampTicketParser() {}
    BitstampTicketParser(const BitstampTicketParser &) = delete;
    BitstampTicketParser(BitstampTicketParser &&) = delete;
    virtual ~BitstampTicketParser() {}

    Ticket parse(std::string _data);
};

#endif
