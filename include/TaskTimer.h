#ifndef TASK_TIMER_H
#define TASK_TIMER_H

class TaskTimer
{
  public:
    TaskTimer();
    ~TaskTimer();
    void tick();
    void repeat(unsigned int interval, void (*eventHandler)());
    void once(unsigned int delay, void (*eventHandler)());
  private:
    unsigned long _lastTick;
    unsigned int _interval;
    unsigned int _delay;
    void (*_eventHandler)();
    void checkOnce(unsigned long now);
    void checkInterval(unsigned long now);
};

#endif
