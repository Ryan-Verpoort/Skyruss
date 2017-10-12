#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
    Timer();
    void Start();
    void Stop();
    float getProcessTime();
    float getDuration();

private:
    float _StartTime;
    float _FinalTime;
};

#endif