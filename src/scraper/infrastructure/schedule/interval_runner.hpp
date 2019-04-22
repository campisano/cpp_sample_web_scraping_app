#ifndef INTERVAL_RUNNER__HPP__
#define INTERVAL_RUNNER__HPP__

#include <memory>
#include "command_recurrence.hpp"

class IntervalRunner
{
public:
    explicit IntervalRunner(
        std::unique_ptr<CommandRecurrence> _cmd_rec,
        bool & _to_continue
    );
    IntervalRunner(const IntervalRunner &) = delete;
    IntervalRunner(IntervalRunner &&) = default;
    virtual ~IntervalRunner();

    void run();

private:
    std::unique_ptr<CommandRecurrence> m_cmd_rec;
    bool & m_to_continue;
};

#endif
