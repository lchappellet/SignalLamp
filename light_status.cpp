#include "light_status.h"

//light_status::light_status() {}

LightColor light_status::set_light_color(double sensor_reading, double timer) {
  if (timer >= 3000 && sensor_reading <= 15) {
    // Turn on the red light.
    light = LightColor::kRed;
  }

  if (timer >= 3000 && sensor_reading >= 60) {
    // Turn on green light.
    light = LightColor::kGreen;
  }

  if (timer >= 3000 && sensor_reading > 15 && sensor_reading < 60) {
    // Turn on yellow light.
    light = LightColor::kYellow;
  }

  return light;
}
