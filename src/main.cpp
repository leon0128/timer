#include <iostream>

#include <unistd.h>

#include "timer.hpp"

int main(int argc, char **argv)
{
    Timer<> timer; // default(high resolution clock) timer
    Timer<std::chrono::system_clock> systemTimer; // system clock timer

    timer.start();
    sleep(1);
    timer.lap();
    std::cout << "lap-time: " << timer.count() << std::endl;
    sleep(1);
    timer.stop();
    std::cout << "duration-time: " << timer.count() << std::endl;
    std::cout << "duration-time(milliseconds): " << timer.count<std::chrono::milliseconds>() << std::endl;

    timer.reset();
    std::cout << "reset: " << timer.count() << std::endl;
    timer.set(std::chrono::seconds(100));
    std::cout << "set 100s: " << timer.count() << std::endl;
    timer.set(std::chrono::microseconds(10000000));
    std::cout << "set(1000000microseconds): " << timer.count() << std::endl;

    return 0;
}