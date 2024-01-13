#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "TaskTimer.h"

using std::cout;
using std::endl;
using std::to_string;

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

void delay(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

class Critters
{
public:
  static void blink()
  {
    static bool isOn = false;
    cout << "blink: " << (isOn ? "ON" : "OFF") << endl;
  }

  static void fadeOut()
  {
    const uint8_t FADE_RATE = 5;
    static uint8_t value = 100;

    if (value == 0)
    {
      return;
    }

    value = (value < FADE_RATE) ? 0 : value - FADE_RATE;
    cout << "fadeOut: " << to_string(value) << endl;
  }

  static void fade()
  {
    static uint8_t value = 0;
    static uint8_t step = 5;

    cout << "fade: " << to_string(value) << endl;

    if (value == 0)
    {
      step = 5;
    }
    else if (value == 100)
    {
      step = -5;
    }
    value += step;
  }
};

// defined here just for funsies
TaskTimer *blinkTimer;
TaskTimer *fadeOutTimer;

int main()
{
  // again, just for funsies
  void (*blinkPtr)() = &Critters::blink;
  void (*fadeOutPtr)() = &Critters::fadeOut;

  blinkTimer = new TaskTimer();
  blinkTimer->repeat(250, blinkPtr);

  fadeOutTimer = new TaskTimer();
  fadeOutTimer->repeat(15, fadeOutPtr);

  TaskTimer *fadeTimer = new TaskTimer();
  fadeTimer->repeat(10, &Critters::fade);

  int counter = 0;
  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    cout << "t" << counter << endl;
    counter++;

    blinkTimer->tick();
    fadeOutTimer->tick();
    fadeTimer->tick();

    delay(CLOCK_INTERVAL);
  }
  return 0;
}
