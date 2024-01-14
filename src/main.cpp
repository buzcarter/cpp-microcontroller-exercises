#include <iostream>

#include "buttonDemo.h"
#include "delay.h"
#include "LEDActions.h"
#include "TaskManager.h"

#define CLOCK_INTERVAL 25
#define PROGRAM_DURATION 2000

void setup()
{
  TaskManager::add()->repeat(1000, &LEDActions::blink);
  TaskManager::add()->repeat(15, &LEDActions::fadeOut);
  TaskManager::add()->repeat(10, &LEDActions::fade);
  setupEventDemo(CLOCK_INTERVAL);
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
