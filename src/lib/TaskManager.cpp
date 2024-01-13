#include <vector>
#include "TaskManager.h"
#include "TaskTimer.h"

using std::vector;

vector<TaskTimer*> TaskManager::_task_mgr_timers;

TaskTimer* TaskManager::add()
{
  TaskTimer *nextTimer = new TaskTimer();
  _task_mgr_timers.push_back(nextTimer);
  return nextTimer;
}

void TaskManager::tick()
{
  for (auto timer : _task_mgr_timers)
  {
    timer->tick();
  }
}
