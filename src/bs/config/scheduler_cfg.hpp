#ifndef SCHEDULER_CFG__HPP__
#define SCHEDULER_CFG__HPP__

class SchedulerCfg
{
public:
    explicit SchedulerCfg(int _interval);
    virtual ~SchedulerCfg();

    int interval() const { return m_interval; }

private:
    int m_interval;
};

#endif
