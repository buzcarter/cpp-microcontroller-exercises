#ifndef TASK_TIMER_H
#define TASK_TIMER_H

class TaskTimer
{
  public:
    TaskTimer();
    ~TaskTimer();
    void tick();
    unsigned long getLastTick();
    void repeat(unsigned int interval, void (*eventHandler)());
  private:
    unsigned long _lastTick;
    unsigned int _interval;
    void (*_eventHandler)();
};

#endif
