#include "TaskTimer.h"

void TaskTimer::repeat(unsigned int interval, void (*eventHandler)())
{
  _type = TaskTimerType::INTERVAL;
  _delay = interval;
  _eventHandler = eventHandler;
}

void TaskTimer::once(unsigned int delay, void (*eventHandler)())
{
  _type = TaskTimerType::ONCE;
  _delay = delay;
  _eventHandler = eventHandler;
}

void TaskTimer::stop()
{
  _enabled = false;
}

void TaskTimer::tick(unsigned long now)
{
  if (!_enabled || _delay == 0 || (now - _lastTick < _delay))
  {
    return;
  }

  switch (_type)
  {
  case TaskTimerType::ONCE:
    _enabled = false;
    break;
  }

  _lastTick = now;
  _eventHandler();
}
