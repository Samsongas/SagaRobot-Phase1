#ifndef P1M_04_H
#define P1M_04_H

#include <Arduino.h>
#include <math.h>

#define MAX_SPEED 2*M_PI //rad/s
/* 
 * Number of GAPS per radian
 * (distance_between_wheels/2) / (pi*wheel_diameter/gaps_per_turn)
 */
#define GAPS_PER_RAD (0.13/2)/(M_PI*0.07/20)

/* 
 * Number of mm per gap
 * 20 gaps per complete wheel turn / (pi * wheel_diameter (mm))
 */
#define MM_PER_GAP 20/( M_PI*70 )

/*
 * Checks if rotation movement is needed.
 * Checks if there is a gap at the left.
 * If true, advances to new corridor.
 * Else, checks if there is an obstacle in front.
 * If true, turns left and keeps advancing.
 */
void rotation_movement();

#endif /* P1M_04_H */
