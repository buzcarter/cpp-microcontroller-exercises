#ifndef DELAY_H
#define DELAY_H

#include <chrono>
#include <thread>

void delay(int ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

#endif
