#ifndef P1M_07_H
#define P1M_07_H

#include <Arduino.h>

/* Wheel direction pins */
#define RIGHT_FW 7
#define RIGHT_BW 8
#define LEFT_FW 9
#define LEFT_BW 12

/* Wheel acceleration pins */
#define RIGHT_ACC 10
#define LEFT_ACC 11

/* Max value of Arduino PWM */
#define PWM_MAX 255.0

/* Speed reduction */
#define SPEED_RED 0.5

/* 
 * Initializes all the pins to their
 * corresponding modes.
 */
void initialize_p1m_07();


/*
 * Gives the motors the desired acceleration,
 * expressed in percentage [0.0, 1.0]
 */
float set_speed(float motorL, float motorR);

#endif /* P1M_07 */
