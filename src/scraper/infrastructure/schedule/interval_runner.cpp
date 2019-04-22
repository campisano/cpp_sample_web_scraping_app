#include "interval_runner.hpp"

#include <chrono>
#include <thread>

IntervalRunner::IntervalRunner(
    std::unique_ptr<CommandRecurrence> _cmd_rec,
    bool & _to_continue
) : m_cmd_rec(std::move(_cmd_rec)), m_to_continue(_to_continue)
{
}

IntervalRunner::~IntervalRunner()
{
}

void IntervalRunner::run()
{
    while(m_to_continue)
    {
        auto start = std::chrono::high_resolution_clock::now();
        m_cmd_rec->command->execute();
        auto end = std::chrono::high_resolution_clock::now();
        long elapsed = (std::chrono::duration_cast<std::chrono::milliseconds>
                        (end - start)).count();

        if(m_cmd_rec->interval > elapsed)
        {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(m_cmd_rec->interval - elapsed));
        }
    }
}
