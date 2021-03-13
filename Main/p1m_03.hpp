#ifndef P1M_03_H
#define P1M_03_H

#include <Arduino.h>
#include <math.h>

#define SIDE_DISTANCE 350

#define MAX_SPEED 1.5 * M_PI //rad/s
/* Value calculated in modules */
//#define DIFF_DRV 0.976
/* Value found tuning */
#define DIFF_DRV 0.8
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
void straight_line_movement(unsigned s1d,unsigned s2d,unsigned s3d,unsigned s4d);

#endif /* P1M_03_H */
