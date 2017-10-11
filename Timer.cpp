#include "Timer.h"

using namespace std;

Timer::Timer()
{
    _StartTime = 0;
    _FinalTime = 0;
}

void Timer::Start()
{
    _StartTime = getProcessTime();
}

double Timer::Stop()
{
    return getProcessTime() - _StartTime;
}

double Timer::getDuration()
{
    return getProcessTime();
}

double Timer::getProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}