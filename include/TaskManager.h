#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <iostream>
#include <vector>
#include "TaskTimer.h"

using std::vector;

vector<TaskTimer*> _task_mgr_timers;

class TaskManager {
public:
  static TaskTimer* add() {
      TaskTimer *nextTimer = new TaskTimer();
      _task_mgr_timers.push_back(nextTimer);
      return nextTimer;
  }
  static void tick() {
    for (auto timer : _task_mgr_timers)
    {
      timer->tick();
    }
  }
};

#endif
