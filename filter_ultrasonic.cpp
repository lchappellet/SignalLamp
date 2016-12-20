#include "filter_ultrasonic.h"

Filter_ultrasonic::Filter_ultrasonic() {}

double Filter_ultrasonic::average_ping_filter() {
  int count = 0;
  double total_distance_value = 0.0;

  for (int i = 0; i < 10; i++) {
    ping_value = sonar.ping_cm();
    if (ping_value == 0 || ping_value >= 250) {
      continue;
    }
    count++;
    total_distance_value += ping_value;
    Serial.print("ping value is");
    Serial.println(ping_value);
  }

  double avg_distance_total =
      total_distance_value / count;  // calc. Average ping value

  Serial.print("total_distance_value: ");
  Serial.println(total_distance_value);
  Serial.print("Average Total");
  Serial.println(avg_distance_total);
  delay(500);
  return avg_distance_total;
};
