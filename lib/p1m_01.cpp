#include "p1m_01.hpp"

/* Initializes all the pins to their
 * corresponding modes.
 */
void initialize()
{
	/* Pulse sending pins */
	pinMode(S_1, OUTPUT);
	pinMode(S_2, OUTPUT);
	pinMode(S_3, OUTPUT);
	pinMode(S_4, OUTPUT);
	/* Pulse reading pin */
	pinMode(ECHO, INPUT);	
}

/*
 * Receives the as input a sensor.
 * Returns distance of obstacle detected
 * by sensor, in mm.
 */
unsigned distance_sensor(int sensor){
	/* Send a 10 us pulse trough trigger pin */
	switch (sensor)
	{
		case 1:
			digitalWrite(S_1, HIGH);
			delayMicroseconds(10); //10us pulse
			digitalWrite(S_1, LOW);
			break;
		case 2:
			digitalWrite(S_2, HIGH);
			delayMicroseconds(10); //10us pulse
			digitalWrite(S_2, LOW);
			break;
		case 3:
			digitalWrite(S_3, HIGH);
			delayMicroseconds(10); //10us pulse
			digitalWrite(S_3, LOW);
			break;
		case 4:
			digitalWrite(S_4, HIGH);
			delayMicroseconds(10); //10us pulse
			digitalWrite(S_4, LOW);
			break;
	
	/* Read the width of the pulse sent
	   by the sensor */
	int t;
	t = pulseIn(ECHO, HIGH);
	distance = (10*t)/59;
	return distance;
}