class MyTimer
{
  public:
    MyTimer();
    ~MyTimer();
    void tick();
    unsigned long getLastTick();
    void repeat(unsigned int interval);
  private:
    unsigned long _lastTick;
    unsigned int _interval;
};
