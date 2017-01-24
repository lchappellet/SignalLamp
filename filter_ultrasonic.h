#ifndef FILTER_ULTRASONIC_H
#define FILTER_ULTRASONIC_H
#pragma once

class Filter_ultrasonic
{
     public:
      double average_ping_filter(double sonar_ping);
     private:
      double ping_value = 0.0;
};

#endif // FILTER_ULTRASONIC_H
