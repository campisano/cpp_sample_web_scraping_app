#ifndef BITSTAMP_TICKET_PARSER__HPP__
#define BITSTAMP_TICKET_PARSER__HPP__

#include "ticket_parser.hpp"

class BitstampTicketParser : public TicketParser
{
public:
    explicit BitstampTicketParser() = default;
    BitstampTicketParser(const BitstampTicketParser &) = delete;
    BitstampTicketParser(BitstampTicketParser &&) = delete;
    virtual ~BitstampTicketParser() = default;

    BitstampTicketParser & operator=(const BitstampTicketParser &) = delete;
    BitstampTicketParser & operator=(BitstampTicketParser &&) = delete;

public:
    Ticket parse(std::string _data);
};

#endif
