#include <vector>
#include "millis.h"
#include "TaskManager.h"
#include "TaskTimer.h"

using std::vector;

vector<TaskTimer*> TaskManager::_task_mgr_timers;

TaskTimer* TaskManager::add()
{
  TaskTimer *timer = new TaskTimer();
  _task_mgr_timers.push_back(timer);
  return timer;
}

void TaskManager::tick()
{
  const unsigned long now = millis();
  for (auto timer : _task_mgr_timers)
  {
    timer->tick(now);
  }
  // TODO: remove timers that are no longer enabled?
}
