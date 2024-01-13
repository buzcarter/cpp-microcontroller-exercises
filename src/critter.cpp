#include <chrono>
#include <iostream>
#include <thread>

#include "TaskTimer.h"
#include "Critters.h"
#include "EventMgr.h"
#include "EventTypes.h"
#include "TaskManager.h"

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

void delay(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int toInt(EventTypes eventType)
{
  return static_cast<int>(eventType);
}

const int BTN_PRESS_EVENT = toInt(EventTypes::BtnPressed);

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
  // TaskManager::init();
  TaskTimer *t0 = TaskManager::add();
  t0->repeat(1000, &Critters::blink);
  TaskTimer *t1 = TaskManager::add();
  t1->repeat(15, &Critters::fadeOut);
  TaskTimer *t2 = TaskManager::add();
  t2->repeat(10, &Critters::fade);
  // TaskManager::add().once(18 * CLOCK_INTERVAL, &firstBtnPress);
  // TaskManager::add().once(49 * CLOCK_INTERVAL, &secondBtnPress);

  /*
    // Blink
    TaskTimer *blinkTimer = new TaskTimer();
    blinkTimer->repeat(250, &Critters::blink);

    // FadeOut
    TaskTimer *fadeOutTimer = new TaskTimer();
    fadeOutTimer->repeat(15, &Critters::fadeOut);

    // Fade
    TaskTimer *fadeTimer = new TaskTimer();
    fadeTimer->repeat(10, &Critters::fade);
  */

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

    TaskManager::tick();
    // blinkTimer->tick();
    // fadeOutTimer->tick();
    // fadeTimer->tick();
    firstTimeOutEvent->tick();
    secondTimeOutEvent->tick();

    delay(CLOCK_INTERVAL);
  }
  return 0;
}
