#ifndef TIMER_H
#define TIMER_H

#include <ctime>
/**
 * @class Timer
 * @author Brandon Verkerk
 * @date 13/10/2017
 * @file Timer.h
 * @brief Timer Class
 *
 * Provides timing related data to all functions to allow for the creation and deletion of specific objects
 */
class Timer
{
public:
    /**
     * @brief Default Constructor for Timer class
     *
     * Initialises the start and final time of the game to 0
     */
    Timer();

    /**
     * @brief Recieves the process time from the system clock
     */
    void Start();

    /**
     * @brief Recieves the current process time and stores that as the _finalTime
     */
    void Stop();

    /**
     * @brief Recieves the current clock time of the system
     * @return time / CLOCKS_PER_SEC
     */
    float getProcessTime();

    /**
     * @brief Calculates the run time duation by subtracting the _StartTime from the _FinalTIme
     * @return  _FinalTime - _StartTime
     */
    float getDuration();

private:
    float _StartTime;
    float _FinalTime;
};

#endif