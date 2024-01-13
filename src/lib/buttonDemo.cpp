#include <iostream>

#include "buttonDemo.h"
#include "EventManager.h"
#include "EventTypes.h"
#include "TaskManager.h"

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

int pressedCount = 0;

void btnPressed()
{
  EventManager::publish(BTN_PRESS_EVENT);
  if (pressedCount == 0)
  {
    EventManager::unsubscribe(BTN_PRESS_EVENT, btnBSubscr);
  }
  pressedCount++;
}

/**
 * This code simulates two button pushes after a certain number of clock ticks
 * and demonstrates the functionality of the EventManager's event publishing,
 * subscribing, and unsubscribing actions.
 *
 * In this demonstration, there are two subscribers to the button press event.
 * Both subscribers are triggered by the first button press, which is a clocked
 * action. However, one of the event handlers unsubscribes after the first button
 * press, ensuring that only one handler will be invoked for the second button
 * press.
 */
void setupEventDemo(int clockInterval) {
  TaskManager::add()->once(18 * clockInterval, &btnPressed);
  TaskManager::add()->once(49 * clockInterval, &btnPressed);

  EventManager::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseA);
  btnBSubscr = EventManager::subscribe(BTN_PRESS_EVENT, &onBtnPressResponseB);
}
