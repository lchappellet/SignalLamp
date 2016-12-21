#include "time_passed.h"

//time_passed::time_passed() {}

double time_passed::time(long unsigned int milliseconds) {
  if (time_now < milliseconds) {
    time_now = milliseconds;
  }

  time_total_passed = time_now - previous_time;
  return time_total_passed;
}

void time_passed::time_reset() { previous_time = time_now; }
