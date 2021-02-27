#ifndef P1M_03_H
#define P1M_03_H

#include <Arduino.h>
#include <math.h>

#define MAX_SPEED 2*M_PI //rad/s
#define DIFF_DRV 0.976
/* 
 * Number of GAPS per radian
 * (distance_between_wheels/2) / (pi*wheel_diameter/gaps_per_turn)
 */
#define GAPS_PER_RAD (0.13/2)/(M_PI*0.07/20)

/*
 * Checks if straight movement is needed.
 * Checks rotation of robot in corridor.
 * Corrects the rotation if necessary.
 * Advances in a straight line.
 */
void straight_line_movement();

#endif /* P1M_03_H */