#include <chrono>
#include <iostream>
#include <thread>
#include "sandbox.h"

using std::cout;
using std::endl;

#define CLOCK_INTERVAL 100
#define PROGRAM_DURATION 2000

int main()
{
  int counter = 0;
  cout << (isSwingSetAvailable() ? "Go to the park now" : "You'd better wait") << endl;

  while (counter < PROGRAM_DURATION / CLOCK_INTERVAL)
  {
    cout << "Tick #" << counter << endl;
    counter++;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
