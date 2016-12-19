#include "time_passed.h"

time_passed::time_passed() {}

double time_passed::time() {
  if (time_now < millis()) {
    previous_time = time_now;
    time_now = millis();
  }

  time_total_passed = time_now - previous_time;
  return time_total_passed;
}