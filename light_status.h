
#pragma once
#ifndef LIGHT_STATUS_H
#define LIGHT_STATUS_H


class light_status{

public:
 double light_color(double sensor_reading, double timer);
private:
 int color_value = 0;
 int light= 0;

};


#endif // LIGHT_STATUS_H
