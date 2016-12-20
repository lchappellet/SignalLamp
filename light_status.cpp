#include "light_status.h"

light_status::light_status() {}

int light_status::light_color(double sensor_reading, double timer) {
  if (timer >= 1000 && sensor_reading <= 15) {
    // turn on the red light.
    light = 0;
  }

  if (timer >= 1000 && sensor_reading >= 60) {
    // turn on yellow light
    light = 1;
  }

  if (timer >= 1000 && sensor_reading > 15 && sensor_reading < 60) {
    // turn on yellow light
    light = 2;
  }

  return light;
  /* enum color { RED, GREEN, YELLOW };

   switch (light) {
     case RED:
       std::cout << "red\n";
       return light;
       break;
     case GREEN:
       std::cout << "green\n";
       return light;
       break;
     case YELLOW:
       std::cout << "yellow\n";
       return light;
       break;
   }
   */
}
