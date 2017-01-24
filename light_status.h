
#pragma once
#ifndef LIGHT_STATUS_H
#define LIGHT_STATUS_H

enum LightColor {
  kRed = 0,
  kYellow,
  kGreen,
};

class light_status {
public:
 LightColor set_light_color(double sensor_reading, double timer);
 LightColor get_light_color() const {
  return light;
 }
private:
 LightColor light = kGreen;
};


#endif // LIGHT_STATUS_H
