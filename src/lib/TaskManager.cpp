#include <vector>
#include <algorithm> // for std::remove_if
#include "millis.h"
#include "TaskManager.h"
#include "TaskTimer.h"

using std::vector;

vector<TaskTimer *> TaskManager::_task_mgr_timers;

TaskTimer *TaskManager::add()
{
  TaskTimer *timer = new TaskTimer();
  _task_mgr_timers.push_back(timer);
  return timer;
}

void TaskManager::gc()
{
  _task_mgr_timers.erase(
      std::remove_if(
          _task_mgr_timers.begin(),
          _task_mgr_timers.end(),
          [](TaskTimer *timer)
          {
            return timer->isFinsihed();
          }),
      _task_mgr_timers.end());
}

void TaskManager::tick()
{
  const unsigned long now = millis();
  for (auto timer : _task_mgr_timers)
  {
    timer->tick(now);
  }
  gc();
}
