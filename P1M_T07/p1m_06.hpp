
#ifndef P1M_06_H
#define P1M_06_H

#include <Arduino.h>

#include "p1m_02.hpp"
#include "p1m_07.hpp"


/*
* PID parameters
*/
#define Default_Ki 1
#define Default_Kd 1
#define Default_Kp 10


/* 
 * General PID implementation.
 */
float PID(float DesiredValue, float ActualValue);
/* 
 * Set the motor to the desired speed and distance
 * unless distance it's 0, then it works indefinitely
 */
void call_PID(float dsmL, float dsmR, unsigned ddmL, unsigned ddmR);

/*
 * Set PID parameters.
 */
void SetPIDparameter(float ki, float kd, float kp);

#endif /* P1M_06_H */
