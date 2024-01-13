#include <chrono>
#include <iostream>
#include <thread>

#include "TaskTimer.h"
#include "Critters.h"

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

void delay(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

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
    std::cout << "t" << counter << std::endl;
    counter++;

    blinkTimer->tick();
    fadeOutTimer->tick();
    fadeTimer->tick();

    delay(CLOCK_INTERVAL);
  }
  return 0;
}
