#ifndef TASK_TIMER_H
#define TASK_TIMER_H

#include <cstdint>

enum class TaskTimerType : int8_t
{
  UNASSIGNED,
  ONCE,
  INTERVAL,
};

class TaskTimer
{
  public:
    TaskTimer();
    ~TaskTimer();
    void tick(unsigned long now);
    void repeat(unsigned int interval, void (*eventHandler)());
    void once(unsigned int delay, void (*eventHandler)());
  private:
    unsigned long _lastTick;
    unsigned int _interval;
    unsigned int _delay;
    TaskTimerType _type;
    void (*_eventHandler)();
    void checkOnce(unsigned long now);
    void checkInterval(unsigned long now);
};

#endif
