#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include "TaskTimer.h"

using std::vector;

class TaskManager
{
private:
  static vector<TaskTimer *> _task_mgr_timers;

public:
  static TaskTimer *add();
  static void tick();
};

#endif
