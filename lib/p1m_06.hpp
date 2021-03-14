
#ifndef P1M_06_H
#define P1M_06_H

#include <Arduino.h>


/*
* PID parameters
*/
#define Default_Kp 1
#define Default_Ki 0
#define Default_Kd 0
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

/* 
 * Set the motor to the desired speed in rad/s and distance in mm
 * unless distance it's 0, then it works indefinitely
 */
void call_PID(float dsmL, float dsmR, unsigned ddmL, unsigned ddmR);

/*
 * Set PID parameters.
 */
void SetPIDparameter(float ki, float kd, float kp);

#endif /* P1M_06_H */
