#include "http_server.hpp"

#include <iostream>
#include <functional>

HttpServer::HttpServer()
{
    m_service = std::unique_ptr<restbed::Service>(new restbed::Service());
}

HttpServer::~HttpServer()
{
    stop();
}

void HttpServer::notFound(
    const std::function <void (
        const std::shared_ptr< restbed::Session >)
    > & _handler)
{
    m_service->set_not_found_handler(_handler);
}

void HttpServer::route(
    const std::string & _path,
    const std::string & _method,
    const std::function <void (
        const std::shared_ptr< restbed::Session >)
    > & _handler)
{
    auto resource = std::make_shared<restbed::Resource>();
    resource->set_path(_path);
    resource->set_method_handler(_method, _handler);
    m_service->publish(resource);
}

void HttpServer::start(
    const std::string & _ip,
    unsigned int _port,
    unsigned int _threads)
{
    if(!m_thread_service)
    {
        m_service->set_ready_handler(std::bind(
                                         &HttpServer::handle_startup_message,
                                         this,
                                         std::placeholders::_1));

        auto settings = std::make_shared<restbed::Settings>();
        settings->set_bind_address(_ip);
        settings->set_port(_port);
        settings->set_default_header("Connection", "close");
        settings->set_worker_limit(_threads);

        m_thread_service = std::unique_ptr<std::thread>(
                               new std::thread(
                                   [this, settings]()
        {
            m_service->start(settings);
        }));
    }
}

void HttpServer::wait()
{
    if(m_thread_service)
    {
        m_thread_service->join();
    }
}

void HttpServer::stop()
{
    if(m_thread_service)
    {
        m_service->stop();
    }

    wait();
}

void HttpServer::handle_startup_message(restbed::Service &)
{
    std::cout << "service fired up at "
              << m_service->get_http_uri()->to_string() << std::endl;
}
