#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer 
{
	public:
		
		Timer();
		void Start();
		double Stop();
		double getProcessTime();
		double getDuration();
	
	private:
			
		double _StartTime;
		double _FinalTime;

	};
  


#endif