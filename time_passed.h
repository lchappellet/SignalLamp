#ifndef TIME_PASSED_H
#define TIME_PASSED_H
#pragma once

class time_passed
{
public:
    double time(long unsigned int milliseconds);
    void time_reset();
private:

    double time_now = 50;
    double previous_time = 0.0;
    double total_time = 0.0;
    double time_total_passed = 0.0;

};

#endif // TIME_PASSED_H
