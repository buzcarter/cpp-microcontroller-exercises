#ifndef LED_ACTIONS_H
#define LED_ACTIONS_H

#include <iostream>
#include <string>
#include <cstdint>

#include "StdOutColors.h"

using std::cout;
using std::endl;
using std::to_string;

class LEDActions
{
public:
  static void blink(unsigned long now)
  {
    static bool isOn = false;
    isOn = !isOn;
    cout << STD_OUT_COLOR_RED << "blink: " << (isOn ? "ON" : "OFF") << STD_OUT_COLOR_RESET << endl;
  }

  static void fadeOut(unsigned long now)
  {
    const uint8_t FADE_RATE = 5;
    static uint8_t value = 100;

    if (value == 0)
    {
      return;
    }

    value = (value < FADE_RATE) ? 0 : value - FADE_RATE;
    cout << STD_OUT_COLOR_CYAN << "fadeOut: " << to_string(value) << STD_OUT_COLOR_RESET << endl;
  }

  static void fade(unsigned long now)
  {
    static uint8_t value = 0;
    static uint8_t step = 5;

    cout << STD_OUT_COLOR_YELLOW << "fade: " << to_string(value) << STD_OUT_COLOR_RESET << endl;

    if (value == 0)
    {
      step = 5;
    }
    else if (value == 100)
    {
      step = -5;
    }
    value += step;
  }
};


#endif
