#ifndef P1M_05_H
#define P1M_05_H

#include <Arduino.h>
#include <math.h>

#define SNS_DST 140.0 //mm

/*
 * Returns the rotation angle of the robot,
 * given as inputs the distance sensed by
 * sensor 3 and 4 (side sensors).
 */
float get_rotation(unsigned s3d, unsigned s4d);

#endif /* P1M_05_H */
