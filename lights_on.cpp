#include "lights_on.h"

lights_on::lights_on() {}

void lights_on::set_lights(int lights) {
  enum color { RED, GREEN, YELLOW };

  switch (lights) {
    case RED:
      digitalWrite(light_red, LOW);
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, HIGH);
      break;
    case GREEN:
      digitalWrite(light_red, HIGH);
      digitalWrite(light_green, LOW);
      digitalWrite(light_yellow, HIGH);

      break;
    case YELLOW:
      digitalWrite(light_red, HIGH);
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, LOW);

      break;
  }
}
