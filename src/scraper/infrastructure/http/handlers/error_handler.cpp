#include "error_handler.hpp"

#include <string>

ErrorHandler::ErrorHandler()
{
}

ErrorHandler::~ErrorHandler()
{
}

void ErrorHandler::notFound(const std::shared_ptr< restbed::Session > _session)
{
    std::string type = "text/plain";
    std::string body = "Unknown request: \""
                       + _session->get_request()->get_path()
                       + "\"\n";
    const std::multimap< std::string, std::string > headers
    {
        { "Content-Type", type },
        { "Content-Length", std::to_string(body.length()) }
    };
    _session->close(restbed::OK, body, headers);
}
