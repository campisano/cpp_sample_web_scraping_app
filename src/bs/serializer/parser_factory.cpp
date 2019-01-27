#include "parser_factory.hpp"

#include <sstream>
#include <stdexcept>
#include "bitstamp_ticket_parser.hpp"
#include "cex_ticket_parser.hpp"

std::unique_ptr<TicketParser> ParserFactory::create(std::string _parser_name)
{
    if(_parser_name == "bitstamp_v2")
    {
        return std::unique_ptr<TicketParser>(new BitstampTicketParser());
    }

    if(_parser_name == "cex")
    {
        return std::unique_ptr<TicketParser>(new CexTicketParser());
    }

    std::stringstream msg;
    msg << "Unknown parser specified [" << _parser_name << "]" << std::endl;
    throw std::runtime_error(msg.str());
}
