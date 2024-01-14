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
  void restart();

  void finished();
  bool isFinsihed();

  void tick(unsigned long now);

  void repeat(unsigned int interval, void (*eventHandler)(unsigned long now));
  void once(unsigned int delay, void (*eventHandler)(unsigned long now));
private:
  bool _enabled = true;
  bool _finished = false;
  unsigned long _lastTick = 0;
  unsigned int _delay = 0;
  TaskTimerType _type = TaskTimerType::UNASSIGNED;
  void (*_eventHandler)(unsigned long now);
};

#endif
