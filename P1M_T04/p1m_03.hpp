#ifndef P1M_03_H
#define P1M_03_H

#include <Arduino.h>
#include <math.h>

#define MAX_SPEED 2*M_PI //rad/s

/*
 * Checks if straight movement is needed.
 * Checks rotation of robot in corridor.
 * Corrects the rotation if necessary.
 * Advances in a straight line.
 */
void straight_line_movement();

#endif /* P1M_03_H */
