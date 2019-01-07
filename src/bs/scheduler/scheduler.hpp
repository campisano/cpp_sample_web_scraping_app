#ifndef SCHEDULER__HPP__
#define SCHEDULER__HPP__

#include "../config/scheduler_cfg.hpp"
#include "command.hpp"

class Scheduler
{
 public:
  explicit Scheduler(const SchedulerCfg & _config, Command & _command);
  virtual ~Scheduler();

  void run();

 private:
  SchedulerCfg m_config;
  Command & m_command;
};

#endif
