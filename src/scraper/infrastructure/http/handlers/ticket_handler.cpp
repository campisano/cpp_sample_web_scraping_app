#include "ticket_handler.hpp"

#include <json.hpp>
#include <string>

// TODO[cmp] put this elsewhere
void to_json(nlohmann::json & _j, const Ticket & _t)
{
    _j = nlohmann::json
    {
        {"timestamp", _t.timestamp()},
        {"low", _t.low()},
        {"high", _t.high()},
        {"last", _t.last()},
        {"bid", _t.bid()},
        {"ask", _t.ask()},
        {"volume", _t.volume()},
        {"source", _t.source()}};
}

void from_json(const nlohmann::json & _j, Ticket & _t)
{
    _t = Ticket(
             _j.at("timestamp").get<long>(),
             _j.at("low").get<long>(),
             _j.at("high").get<long>(),
             _j.at("last").get<long>(),
             _j.at("bid").get<long>(),
             _j.at("ask").get<long>(),
             _j.at("volume").get<long>(),
             _j.at("source").get<long>()
         );
}






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
        json.push_back(t);
    }

    std::string body = json.dump();

    const std::multimap< std::string, std::string > headers
    {
        { "Content-Type", type },
        { "Content-Length", std::to_string(body.length()) }
    };
    _session->close(restbed::OK, body, headers);
}
