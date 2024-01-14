#include <iostream>
#include <cstdint>
#include <functional> // for std::bind

#include "StdOutColors.h"
#include "TaskManager.h"
#include "TaskTimer.h"

using std::to_string;

class FadeBehavior
{
private:
  int _initialValue;
  int _finalValue;
  int _duration;
  TaskTimer *_timer;

public:
  FadeBehavior(int initialValue, int finalValue, int duration) : _initialValue(initialValue), _finalValue(finalValue), _duration(duration)
  {
    _timer = TaskManager::add();
    _timer->repeat(10, &update);
  }

  TaskTimer *timer()
  {
    return _timer;
  }

  void update(unsigned long now)
  {
    static uint8_t numCalls = 0;
    /**
     * Need a reasonable guess for `fadeRate` on first pass, thereafter, calculate where we are (`currentValue`)
     * compared to where we want to be (`finalValue`) and how many calls we have to get there.
     */
    static uint8_t fadeRate = (_initialValue - _finalValue) / _duration; // units/ms
    static uint8_t currentValue = _initialValue;
    static unsigned long startTime = now;

    if (currentValue <= _finalValue)
    {
      return;
    }

    numCalls++;

    uint16_t interval = (now - startTime) / numCalls; // ms
    if (numCalls != 1)
    {
      // fadeRate is a running average of prior rate and most recent rate
      fadeRate = (fadeRate + ((_initialValue - currentValue) / interval)) / 2;
    }

    currentValue = (currentValue < fadeRate) ? _finalValue : currentValue - fadeRate;
    if (currentValue == _finalValue)
    {
      _timer->finished();
    }

    std::cout << STD_OUT_COLOR_CYAN << "fadeOut*: "
              << STD_OUT_COLOR_WHITE << to_string(currentValue)
              << STD_OUT_COLOR_CYAN << " (" << to_string(numCalls) << ", " << to_string(fadeRate) << "/" << to_string(interval) << ", " << to_string((_initialValue - _finalValue) / interval) << ")"
              << STD_OUT_COLOR_RESET << std::endl;
  }
};

namespace Behaviors
{
  using Fade = FadeBehavior;
}

class TrainDemo
{
private:
  int _currentSpeed = 100;

public:
  void stop(int duration)
  {
    Behaviors::Fade *fade = new Behaviors::Fade(this->_currentSpeed, 0, duration);
  }
};
