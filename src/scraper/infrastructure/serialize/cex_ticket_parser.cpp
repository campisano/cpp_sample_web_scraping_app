#include "cex_ticket_parser.hpp"

#include <json.hpp>
#include <iostream>

Ticket CexTicketParser::parse(std::string _data)
{
    nlohmann::json js = nlohmann::json::parse(_data);
    std::cout << js.dump() << std::endl;

    long source = 2;

    return Ticket
    {
        static_cast<long>(std::stod(js["timestamp"].get<std::string>())),
        static_cast<long>(std::stod(js["low"].get<std::string>()) * 100),
        static_cast<long>(std::stod(js["high"].get<std::string>()) * 100),
        static_cast<long>(std::stod(js["last"].get<std::string>()) * 100),
        static_cast<long>(js["bid"].get<double>() * 100),
        static_cast<long>(js["ask"].get<double>() * 100),
        static_cast<long>(std::stod(js["volume"].get<std::string>()) * 100),
        source
    };
}
