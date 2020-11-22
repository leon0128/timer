#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

template<class C = std::chrono::high_resolution_clock>
class Timer
{
public:
    using Clock = C;
    using Duration = typename Clock::duration;
    using Rep = typename Clock::rep;

    constexpr Timer()
        : mPoint()
        , mDuration(){}

    void start()
        {mPoint = Clock::now();}
    void stop()
        {mDuration += Clock::now() - mPoint;}
    void lap()
        {stop();start();}
    
    constexpr void reset()
        {mDuration = Duration();}
    template<class T>
    constexpr void set(T &&t)
        {mDuration = std::chrono::duration_cast<Duration>(std::forward<T>(t));}

    template<class Duration = std::chrono::seconds>
    constexpr typename Duration::rep count() const
        {return std::chrono::duration_cast<Duration>(mDuration).count();}

private:
    std::chrono::time_point<Clock> mPoint;
    Duration mDuration;
};

#endif