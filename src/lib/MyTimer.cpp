#include "MyTimer.h"
#include "millis.h"

MyTimer::MyTimer()
{
  _lastTick = 0;
  _interval = 0;
}

MyTimer::~MyTimer()
{
}

void MyTimer::repeat(unsigned int interval)
{
  _interval = interval;
}

void MyTimer::tick()
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

  _lastTick = now;
}

unsigned long MyTimer::getLastTick()
{
  return _lastTick;
}
