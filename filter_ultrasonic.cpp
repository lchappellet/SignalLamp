#include "filter_ultrasonic.h"



//Filter_ultrasonic::Filter_ultrasonic() {}

double Filter_ultrasonic::average_ping_filter(double sonar_ping) {
  ping_value = 0.9 * ping_value + 0.1 * sonar_ping;
  return ping_value;
}
