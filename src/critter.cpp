#include <chrono>
#include <iostream>
#include <thread>
#include "sandbox.h"
#include "TaskTimer.h"

using std::cout;
using std::endl;

#define CLOCK_INTERVAL      25
#define PROGRAM_DURATION  2000

class Critters {
public:
  static void mumble()
  {
    cout << "mumble mumble mumble murmur murhmurrrh" << endl;
  }

  static void meow()
  {
    cout << "Kitty: meow" << endl;
  }

  static void woof()
  {
    static uint8_t volume = 0;
    cout << "Doggie: woof... " << static_cast<int>(volume) << endl;
    if (volume < 10)
    {
      volume++;
    } else {
      volume = 0;
    }
  }
};

int main()
{
  void (*mumblePtr)() = &Critters::mumble;
  void (*meowPtr)() = &Critters::meow;

  TaskTimer *mumbleTimer;
  mumbleTimer = new TaskTimer();
  mumbleTimer->repeat(250, mumblePtr);

  TaskTimer *meowTimer;
  meowTimer = new TaskTimer();
  meowTimer->repeat(750, meowPtr);

  TaskTimer *woofTimer = new TaskTimer();
  woofTimer->repeat(10, &Critters::woof);

  int counter = 0;
  cout << (isSwingSetAvailable() ? "Go to the park now" : "You'd better wait") << endl;

  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    cout << "t" << counter << endl;
    counter++;

    mumbleTimer->tick();
    meowTimer->tick();
    woofTimer->tick();
    std::this_thread::sleep_for(std::chrono::milliseconds(CLOCK_INTERVAL));
  }

  cout << "You've just wasted about " << mumbleTimer->getLastTick() << "ms" << endl;
  return 0;
}
