#include "TaskTimer.h"

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

void TaskTimer::once(unsigned int delay, void (*eventHandler)())
{
  _delay = delay;
  _eventHandler = eventHandler;
}

void TaskTimer::checkOnce(unsigned long now)
{
  if (_delay == 0)
  {
    return;
  }

  if (now - _lastTick < _delay)
  {
    return;
  }
  _lastTick = now;

  _eventHandler();
  _delay = 0;
}

void TaskTimer::checkInterval(unsigned long now)
{
  if (_interval == 0)
  {
    return;
  }

  if (now - _lastTick < _interval)
  {
    return;
  }
  _lastTick = now;
  _eventHandler();
}

void TaskTimer::tick(unsigned long now)
{
  checkInterval(now);
  checkOnce(now);

}
