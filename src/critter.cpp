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

Subscription bSub;
TaskTimer *timeOutExample;

void onBtnPressResponseA()
{
  std::cout << "Button 'A' pressed!" << std::endl;
}

void onBtnPressResponseB()
{
  std::cout << "Button 'B' pressed!" << std::endl;
}

void firstBtnPress()
{
  EventMgr::publish(BTN_PRESS_EVENT);
  EventMgr::unsubscribe(BTN_PRESS_EVENT, bSub);
}

void secondBtnPress()
{
  EventMgr::publish(BTN_PRESS_EVENT);
}

int main()
{
  // Blink
  TaskTimer *blinkTimer = new TaskTimer();
  blinkTimer->repeat(250, &Critters::blink);

  // FadeOut
  TaskTimer *fadeOutTimer = new TaskTimer();
  fadeOutTimer->repeat(15, &Critters::fadeOut);

  // Fade
  TaskTimer *fadeTimer = new TaskTimer();
  fadeTimer->repeat(10, &Critters::fade);

  // EventMgr, fire BTN_PRESS_EVENT twice. two subscribers.
  TaskTimer *firstTimeOutEvent = new TaskTimer();
  firstTimeOutEvent->once(18 * CLOCK_INTERVAL, &firstBtnPress);

  TaskTimer *secondTimeOutEvent = new TaskTimer();
  secondTimeOutEvent->once(49 * CLOCK_INTERVAL, &firstBtnPress);

  EventMgr::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseA);
  bSub = EventMgr::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseB);

  int counter = 0;
  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    std::cout << "t" << counter << std::endl;
    counter++;

    blinkTimer->tick();
    fadeOutTimer->tick();
    fadeTimer->tick();
    firstTimeOutEvent->tick();
    secondTimeOutEvent->tick();

    delay(CLOCK_INTERVAL);
  }
  return 0;
}
