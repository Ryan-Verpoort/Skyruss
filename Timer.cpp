#include "Timer.h"

using namespace std;

Timer::Timer()
{
    _StartTime = 0;
    _FinalTime = 0;
}

void Timer::Start()
{
	//Get Current Time of Start
    _StartTime = getProcessTime();
}

void Timer::Stop()
{
	//Get Current Time of Stop
    _FinalTime =  getProcessTime();
}

float Timer::getDuration()
{
	//Finial - initial gets Duruation
	Stop();
    return _FinalTime - _StartTime;
}

float Timer::getProcessTime()
{
	//Get time from the clock function
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}