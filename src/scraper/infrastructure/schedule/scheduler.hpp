#ifndef SCHEDULER__HPP__
#define SCHEDULER__HPP__

#include <list>
#include <memory>
#include <thread>
#include "command_recurrence.hpp"
#include "interval_runner.hpp"

class Scheduler
{
public:
    explicit Scheduler();
    Scheduler(const Scheduler &) = delete;
    Scheduler(Scheduler &&) = default;
    virtual ~Scheduler();

    Scheduler & operator=(const Scheduler &) = delete;
    Scheduler & operator=(Scheduler &&) = default;

public:
    void add(std::unique_ptr<CommandRecurrence> _cmd_rec);
    void start();
    void wait();
    void stop();

private:
    std::list<IntervalRunner> m_runners;
    std::list<std::thread> m_threads;
    bool m_to_continue;
};

#endif
