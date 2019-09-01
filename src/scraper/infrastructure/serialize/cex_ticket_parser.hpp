#ifndef CEX_TICKET_PARSER__HPP__
#define CEX_TICKET_PARSER__HPP__

#include "ticket_parser.hpp"

class CexTicketParser : public TicketParser
{
public:
    explicit CexTicketParser() = default;
    CexTicketParser(const CexTicketParser &) = delete;
    CexTicketParser(CexTicketParser &&) = delete;
    virtual ~CexTicketParser() = default;

    CexTicketParser & operator=(const CexTicketParser &) = delete;
    CexTicketParser & operator=(CexTicketParser &&) = delete;

public:
    Ticket parse(std::string _data);
};

#endif
