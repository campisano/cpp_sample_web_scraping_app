#include "scheduler.hpp"

#include <chrono>

Scheduler::Scheduler()
{
    m_to_continue = false;
}

Scheduler::~Scheduler()
{
    stop();
}

void Scheduler::add(std::unique_ptr<CommandRecurrence> _cmd_rec)
{
    m_runners.push_back(IntervalRunner{std::move(_cmd_rec), m_to_continue});
}

void Scheduler::start()
{
    if(m_to_continue)
    {
        stop();
    }

    m_to_continue = true;

    for(auto & irn : m_runners)
    {
        m_threads.push_back(std::thread{&IntervalRunner::run, &irn});
    }
}

void Scheduler::wait()
{
    for(auto & thr : m_threads)
    {
        if(thr.joinable())
        {
            thr.join();
        }
    }
}

void Scheduler::stop()
{
    m_to_continue = false;
    wait();
    m_threads.clear();
}
