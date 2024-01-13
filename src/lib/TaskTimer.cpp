#include "TaskTimer.h"
#include "millis.h"

TaskTimer::TaskTimer()
{
  _lastTick = 0;
  _interval = 0;
}

TaskTimer::~TaskTimer()
{
}

void TaskTimer::repeat(unsigned int interval, void (*eventHandler)())
{
  _interval = interval;
  _eventHandler = eventHandler;
}

void TaskTimer::tick()
{
  if (_interval == 0)
  {
    return;
  }

  const unsigned long now = millis();
  if (now - _lastTick < _interval)
  {
    return;
  }

  _eventHandler();
  _lastTick = now;
}
