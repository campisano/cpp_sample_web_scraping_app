#include "ticket_handler.hpp"

#include <json.hpp>
#include <string>

TicketHandler::TicketHandler(TicketAPI & _ticket_api) :
    m_ticket_api(_ticket_api)
{
}

TicketHandler::~TicketHandler()
{
}

using namespace nlohmann;

void TicketHandler::getTickets(
    const std::shared_ptr< restbed::Session > _session)
{
    std::string type = "application/json";

    auto tickets = m_ticket_api.getTickets();
    nlohmann::json json = nlohmann::json::array();
    for(auto t : tickets)
    {
        json.push_back(
        {
            {"timestamp", t.timestamp()},
            {"low", t.low()},
            {"high", t.high()},
            {"last", t.last()},
            {"bid", t.bid()},
            {"ask", t.ask()},
            {"volume", t.volume()},
            {"source", t.source()}
        });
    }

    std::string body = json.dump();

    const std::multimap< std::string, std::string > headers
    {
        { "Content-Type", type },
        { "Content-Length", std::to_string(body.length()) }
    };
    _session->close(restbed::OK, body, headers);
}
