#include <sandbox.h>

bool isParkOpen()
{
  return true;
}

bool isItRaining()
{
  return false;
}

bool hasTheCreepyWhiteVanMoved()
{
  return true;
}

bool isSwingSetAvailable()
{
  return isParkOpen() && !isItRaining() && hasTheCreepyWhiteVanMoved();
}
