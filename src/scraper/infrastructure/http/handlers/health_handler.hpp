#ifndef HEALTH_HANDLER__HPP__
#define HEALTH_HANDLER__HPP__

#include <memory>
#include <restbed>

class HealthHandler
{
public:
    explicit HealthHandler();
    HealthHandler(const HealthHandler &) = default;
    HealthHandler(HealthHandler &&) = default;
    virtual ~HealthHandler();

    void handle(const std::shared_ptr< restbed::Session > _session);
};

#endif
