#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// A class to encapsulate std::chrono functions to time our code
class Timer
{
private:
    // type aliases to make accessing nested types easier
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1, 1>>;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    // reset the timer
    void reset();

    // returns time elapses between m_beg and when this function is called
    double elapsed() const;
};

#endif