#ifndef ERROR_HANDLER__HPP__
#define ERROR_HANDLER__HPP__

#include <memory>
#include <restbed>

class ErrorHandler
{
public:
    explicit ErrorHandler();
    ErrorHandler(const ErrorHandler &) = default;
    ErrorHandler(ErrorHandler &&) = default;
    virtual ~ErrorHandler();

    void notFound(const std::shared_ptr< restbed::Session > _session);
};

#endif
