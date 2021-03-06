//#include <iostream>
/*
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
}
/*
int main() {
  cout << "Hello world!" << endl;
  return 0;
}

void loop() {
  light_status light;  // object
  previous_color = color;
  Filter_ultrasonic ultrasonic_ping;  // object
  time_passed timed;                  // object
  lights_on turnON;

  color =
      light.light_color(ultrasonic_ping.average_ping_filter(sonar.ping_cm()), timed.time(millis()));
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
*/
// rn on green light when there is no boxes past a certain point.*
//       Turn on the Yellow light when the boxes are getting close or
//    have just gotten less.*
//          Turn on the Red light when the boxes have reached a certain hieght.*
//         Turn on a small noise when the lights change to red.***** /

/* Psuedo Code.
 *  I want to have a ultrasonic hooked up to the rolling tray.
 *  The system should be reading the ultrasonic readings.
 *  It should log how many times the ultrasonic is reading something closer
than 10cm.
 *  It should also log for how long the ultrasonic is reading something
closer than 10cm.
 *  When the altrasonic is reading less than 10cm for more than 10 seconds
then send the notification that the rolling tray is full.
 *  Send the notification to the bluetooth signal generator so that it can
be recieved by the computer or the cell phone.
 *  Check to see if the ultrasonic will notice when the distance is large
for more than 10 seconds.
 *      -send another signal to the cell phone or computer using bluetooth.
 *  Tu//
---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per
second.
//
---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the
ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic
sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in
centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins
and maximum distance.

double total_time = 0.0;
double time_now = 0.0;
double previoustime = 0.0;
double ultrasonic_dist = 0.0;
double avg_distance_total = 0.0;
double avg_distance_value = 0.0;

#define  light_red  8
#define  light_green 7
#define  light_yellow  6
double ping_value =0.0;
          for(int i =0;i<10; i++){
              ping_value = sonar.ping_cm();
void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping
results.
  pinMode(light_red, OUTPUT);  // set pin to input
   pinMode(light_green, OUTPUT);
    pinMode(light_yellow, OUTPUT);
  digitalWrite(light_red, HIGH);
  digitalWrite(light_green, LOW);
  digitalWrite(light_yellow, HIGH);

}


/* Psuedo Code.
 *  I want to have a ultrasonicfor(int i =0;i<10; i++){
              ping_value = sonar.ping_cm();
              if (ping_value >= 200){
                ping_value = 1.5;
              }
              total_distance_value += ping_value;
              Serial.print("ping value is");
              Serial.println(ping_value);
              }
  avg_distance_total = total_distance_value/10;
  Serial.print("total_distance_value: ");
  Serial.println(total_distance_value);
  Serial.print("Average Total");
  Serial.println(avg_distance_total);
  delay(1000);
  return avg_distance_total; hooked up to the rolling tray.
 *  The system should be reading the ultrasonic readings.
 *  It should log how many times the ultrasonic is reading something closer
than 10cm.
 *  It should also log for how long the ultrasonic is reading something
closer than 10cm.
 *  When the altrasonic is reading less than 10cm for more than 10 seconds
then send the notification that the rolling tray is full.
 *  Send the notification to the bluetooth signal generator so that it can
be recieved by the computer or the cell phone.
 *  Check to see if the ultrasonic will notice when the distance is large
for more than 10 seconds.
 *      -send another signal to the cell phone or computer using bluetooth.
 *  Turn on green light when there is no boxes past a certain point.
 *  Turn on the Yellow light whfor(int i =0;i<10; i++){
              ping_value = sonar.ping_cm();
              if (ping_value >= 200){
                ping_value = 1.5;
              }
              total_distance_value += ping_value;
              Serial.print("ping value is");
              Serial.println(ping_value);
              }
  avg_distance_total = total_distance_value/10;
  Serial.print("total_distance_value: ");
  Serial.println(total_distance_value);
  Serial.print("Average Total");
  Serial.println(avg_distance_total);
  delay(1000);
  return avg_distance_total;en the boxes are getting close or have just
gotten less.
 *  Turn on the Red light when the boxes have reached a certain hieght.
 *  Turn on a small noise when the lights change to red.
 *
 *
 *
 *
 */

/* Psuedocode with Classes
* make a class that controls the input from the ultrasonic and filters the
data and outputs the value we want.
* make another class from the state machine and what you want the light to
do depending on what it recieves.
* Make another class about the lights and for the cart to send out when it
recieves the information of what color or mode it is.
* Make another class that will take those values can convert them to pin
settings.

*/
/*
double timenow() {  // we need to know the time it that the ultrasonic sees
                    // something within 10cm.
  double time = millis();

  return time;
}


double avg_dist() {
  double total_distance_value = 0.0;
  double ping_value = 0.0;
  for (int i = 0; i < 10; i++) {
    ping_value = sonar.ping_cm();
    if (ping_value >= 200) {
      ping_value = 1.5;
    }
    total_distance_value += ping_value;
    Serial.print("ping value is");
    Serial.println(ping_value);
  }
  avg_distance_total = total_distance_value / 10;
  Serial.print("total_distance_value: ");
  Serial.println(total_distance_value);
  Serial.print("Average Total");
  Serial.println(avg_distance_total);
  delay(1000);
  return avg_distance_total;
}
*/
