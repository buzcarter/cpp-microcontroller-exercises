#include <iostream>

#include "LEDActions.h"
#include "EventManager.h"
#include "EventTypes.h"
#include "TaskManager.h"
#include "delay.h"

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

const int BTN_PRESS_EVENT = toInt(EventTypes::BtnPressed);

Subscription btnBSubscr;

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
  EventManager::publish(BTN_PRESS_EVENT);
  EventManager::unsubscribe(BTN_PRESS_EVENT, btnBSubscr);
}

void secondBtnPress()
{
  EventManager::publish(BTN_PRESS_EVENT);
}

void setup()
{
  TaskManager::add()->repeat(1000, &LEDActions::blink);
  TaskManager::add()->repeat(15, &LEDActions::fadeOut);
  TaskManager::add()->repeat(10, &LEDActions::fade);
  TaskManager::add()->once(18 * CLOCK_INTERVAL, &firstBtnPress);
  TaskManager::add()->once(49 * CLOCK_INTERVAL, &secondBtnPress);

  EventManager::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseA);
  btnBSubscr = EventManager::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseB);
}

void loop()
{
  TaskManager::tick();
}

int main()
{
  setup();

  int counter = 0;
  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    std::cout << "t" << counter << std::endl;
    counter++;
    loop();
    delay(CLOCK_INTERVAL);
  }
  return 0;
}
