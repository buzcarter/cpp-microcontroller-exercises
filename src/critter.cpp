#include <chrono>
#include <iostream>
#include <thread>

#include "TaskTimer.h"
#include "Critters.h"
#include "EventMgr.h"

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

#define BTN_PRESS_EVENT 1

void delay(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// defined here just for funsies
TaskTimer *blinkTimer;
TaskTimer *fadeOutTimer;

void onBtnPressResponseA()
{
  std::cout << "Button 'A' pressed!" << std::endl;
}

void onBtnPressResponseB()
{
  std::cout << "Button 'B' pressed!" << std::endl;
}

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

  EventMgr::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseA);
  Subscription bSub = EventMgr::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseB);

  int counter = 0;
  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    std::cout << "t" << counter << std::endl;
    counter++;

    blinkTimer->tick();
    fadeOutTimer->tick();
    fadeTimer->tick();

    if (counter == 18) {
      EventMgr::publish(BTN_PRESS_EVENT);
      EventMgr::unsubscribe(BTN_PRESS_EVENT, bSub);
    } else if (counter == 49) {
      EventMgr::publish(BTN_PRESS_EVENT);
    }

    delay(CLOCK_INTERVAL);
  }
  return 0;
}
