#include "health_handler.hpp"

#include <json.hpp>
#include <string>

HealthHandler::HealthHandler()
{
}

HealthHandler::~HealthHandler()
{
}

void HealthHandler::handle(const std::shared_ptr< restbed::Session > _session)
{
    std::string type = "application/json";
    std::string body = nlohmann::json({{"status", "UP"}}).dump();
    const std::multimap< std::string, std::string > headers
    {
        { "Content-Type", type },
        { "Content-Length", std::to_string(body.length()) }
    };
    _session->close(restbed::OK, body, headers);
}
