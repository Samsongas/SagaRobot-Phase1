#ifndef P1M_01_H
#define P1M_01_H

#include <Arduino.h>

#define S_1 A3
#define S_2 A2
#define S_3 A1
#define S_4 A0
#define TRG 6

/* Initializes all the pins to their
 * corresponding modes.
 */
void initialize_p1m_01();

/*
 * Receives the as input a sensor.
 * Returns distance of obstacle detected
 * by sensor, in mm.
 */
unsigned distance_sensor(int sensor);

#endif /* P1M_01_H */
