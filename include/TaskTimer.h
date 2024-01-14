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
  void stop();
  void tick(unsigned long now);
  void repeat(unsigned int interval, void (*eventHandler)());
  void once(unsigned int delay, void (*eventHandler)());

private:
  bool _enabled = true;
  unsigned long _lastTick = 0;
  unsigned int _delay = 0;
  TaskTimerType _type = TaskTimerType::UNASSIGNED;
  void (*_eventHandler)();
};

#endif
