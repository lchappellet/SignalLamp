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

int previous_color = 0;
int color = 0;

void setup() {
  Serial.begin(115200);        // Open serial monitor at 115200 baud
  pinMode(light_red, OUTPUT);  // set pin to input
  pinMode(light_green, OUTPUT);
  pinMode(light_yellow, OUTPUT);
  digitalWrite(light_red, HIGH);
  digitalWrite(light_green, LOW);
  digitalWrite(light_yellow, HIGH);
  Serial.println("starting");
}
/*
int main() {
  cout << "Hello world!" << endl;
  return 0;
}
*/
void loop() {
  light_status light;  // object
  previous_color = color;
  Filter_ultrasonic ultrasonic_ping;  // object
  time_passed timed;                  // object
  lights_on turnON;

  color =
      light.light_color(ultrasonic_ping.average_ping_filter(sonar.ping_cm()), timed.time(millis()));
      Serial.print("color: ");
      Serial.println(color);
      Serial.print("averagePingValue: ");
      Serial.println(ultrasonic_ping.average_ping_filter(sonar.ping_cm()));
      delay(300);
     
  if (previous_color != color) {
    timed.time_reset();
  }
  
  
  switch (color) {
    Serial.print("light value: ");
    Serial.println(color);
    //RED
    case 0:
      digitalWrite(light_red, LOW);
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, HIGH);
      break;
      //GREEN
    case 1:
      digitalWrite(light_red, HIGH);
      digitalWrite(light_green, LOW);
      digitalWrite(light_yellow, HIGH);

      break;
     //YELLOW
    case 2:
      digitalWrite(light_red, HIGH);
      digitalWrite(light_green, HIGH);
      digitalWrite(light_yellow, LOW);

      break;
  }

}
