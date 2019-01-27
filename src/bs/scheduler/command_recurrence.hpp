#ifndef COMMAND_RECURRENCE__HPP__
#define COMMAND_RECURRENCE__HPP__

#include <memory>
#include "command.hpp"

struct CommandRecurrence
{
    std::unique_ptr<Command> command;
    long interval;
};

#endif
