#ifndef DISTANCE_H
#define DISTANCE_H

#include "math.h"
#include "stdint.h"
#include"tm4c123gh6pm.h"
void TURN_ON(float distance,float max_distance); //turns on led if distance is more than max distance
double distance(double X, double Y);// keeps track on distance total distance is returned
#define pi 3.14159265358979323846

#endif
