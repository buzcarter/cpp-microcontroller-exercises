#ifndef LED_ACTIONS_H
#define LED_ACTIONS_H

#include <iostream>
#include <string>
#include <cstdint>

using std::cout;
using std::endl;
using std::to_string;

class LEDActions
{
public:
  static void blink()
  {
    static bool isOn = false;
    isOn = !isOn;
    cout << "blink: " << (isOn ? "ON" : "OFF") << endl;
  }

  static void fadeOut()
  {
    const uint8_t FADE_RATE = 5;
    static uint8_t value = 100;

    if (value == 0)
    {
      return;
    }

    value = (value < FADE_RATE) ? 0 : value - FADE_RATE;
    cout << "fadeOut: " << to_string(value) << endl;
  }

  static void fade()
  {
    static uint8_t value = 0;
    static uint8_t step = 5;

    cout << "fade: " << to_string(value) << endl;

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
