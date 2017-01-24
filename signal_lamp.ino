//#include <iostream>

#include <NewPing.h>
#include "filter_ultrasonic.h"
#include "light_status.h"
#include "lights_on.h"
#include "time_passed.h"

#define TRIGGER_PIN 10  // Arduino pintiedtotrigger pin ontheultrasonic sensor.
#define ECHO_PIN 9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200  // Maximum distance we want to ping for (cm)
                          // distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN,
              MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

#define light_red 8
#define light_green 7
#define light_yellow 6

// State machine that manages light color transitions.
light_status light;

// Create a filter for the noisy ultrasonic data.
Filter_ultrasonic ultrasonic_ping;

// Track the amount of time that has passed.
time_passed timed;

void set_pins(LightColor color) {
   switch (color) {
    case LightColor::kRed:
      digitalWrite(light_red, LOW);
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, LOW);
      break;
    case LightColor::kGreen:
      digitalWrite(light_red, HIGH);
      digitalWrite(light_green, LOW);
      digitalWrite(light_yellow, LOW);
      break;
    case LightColor::kYellow:
      digitalWrite(light_red, LOW);
      digitalWrite(light_green, LOW);
      digitalWrite(light_yellow, HIGH);
      break;
  }
}

void setup() {
  Serial.begin(115200);        // Open serial monitor at 115200 baud
  pinMode(light_red, OUTPUT);  // set pin to input
  pinMode(light_green, OUTPUT);
  pinMode(light_yellow, OUTPUT);
  set_pins(light.get_light_color());
  Serial.println("starting");
}
/*
int main() {
  cout << "Hello world!" << endl;
  return 0;
}
*/
void loop() {
  LightColor previous_color = light.get_light_color();
  double avg_ping_value = ultrasonic_ping.average_ping_filter(sonar.ping_cm());
  
  LightColor new_color =
      light.set_light_color(avg_ping_value, timed.time(millis()));
  Serial.print("color: ");
  Serial.println(new_color);
  Serial.print("averagePingValue: ");
  Serial.println(avg_ping_value);
     
  if (previous_color != new_color) {
    Serial.print("Color changed from ");
    Serial.print(previous_color);
    Serial.print(" to ");
    Serial.println(new_color);

    set_pins(new_color);
    timed.time_reset();
  }
  
  delay(300);
}
