#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include "TaskTimer.h"

using std::vector;

class TaskManager
{
private:
  static vector<TaskTimer *> _task_mgr_timers;
  static void gc();

public:
  static unsigned long _lastTick;
  static TaskTimer *add();
  static void tick();
};

#endif
