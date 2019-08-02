#ifndef HTTP_SERVER__HPP__
#define HTTP_SERVER__HPP__

#include <memory>
#include <restbed>
#include <string>

class HttpServer
{
public:
    void notFound(
        const std::function <void (
            const std::shared_ptr< restbed::Session >)
        > & _handler);

    void route(
        const std::string & _path,
        const std::string & _method,
        const std::function <void (
            const std::shared_ptr< restbed::Session >)
        > & _handler);

    void start(
        const std::string & _ip,
        unsigned int _port,
        unsigned int _threads);

    void wait();
    void stop();

private:
    void handle_startup_message(restbed::Service &);

    restbed::Service m_service;
    std::unique_ptr<std::thread> m_thread_service;
};

#endif
