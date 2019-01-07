#include "scheduler.hpp"

#include <chrono>
#include <thread>

Scheduler::Scheduler(const SchedulerCfg & _config, Command & _command)
    : m_config(_config), m_command(_command)
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::run()
{
    while(true)
    {
        m_command.execute();
        std::this_thread::sleep_for(std::chrono::seconds(
            m_config.interval()));
    }
}
