#ifndef EVENT_TYPES_H
#define EVENT_TYPES_H

enum class EventTypes : int
{
  BtnPressed = 100,
  StationSensorChanged = 200,
  SpeedChanged = 300,
  SpeedStopped = 301,
};

#endif
