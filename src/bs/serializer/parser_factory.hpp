#ifndef PARSER_FACTORY__HPP__
#define PARSER_FACTORY__HPP__

#include <memory>
#include <string>
#include "ticket_parser.hpp"

class ParserFactory
{
public:
    explicit ParserFactory() = delete;

    static std::unique_ptr<TicketParser> create(std::string _parser_name);
};

#endif
