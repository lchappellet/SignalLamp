#pragma once

class Filter_ultrasonic {
 public:
  double average_ping_filter();
 private:
  double ping_value = 0.0;
};

