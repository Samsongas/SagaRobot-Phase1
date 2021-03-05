#include "p1m_01.hpp"

/* Initializes all the pins to their
 * corresponding modes.
 */
void initialize_p1m_01()
{
	/* Pulse sending pins */
	pinMode(S_1, INPUT);
	pinMode(S_2, INPUT);
	pinMode(S_3, INPUT);
	pinMode(S_4, INPUT);
	/* Pulse reading pin */
	pinMode(TRG, OUTPUT);	
}

/*
 * Receives the as input a sensor.
 * Returns distance of obstacle detected
 * by sensor, in mm.
 */
long unsigned distance_sensor(int sensor){
  /* Send a 10 us pulse trough trigger pin */
  digitalWrite(TRG, HIGH);
  delayMicroseconds(10); //10us pulse
  digitalWrite(TRG, LOW);
  /* Read the width of the pulse sent
     by the sensor */
  long int t = 0;
  switch (sensor)
  {
    case 1:
      t = pulseIn(S_1, HIGH);
      break;
    case 2:
      t = pulseIn(S_2, HIGH);
      break;
    case 3:
      t = pulseIn(S_3, HIGH);
      break;
    case 4:
      t = pulseIn(S_4, HIGH);
      break;
  }
  long unsigned distance = (10*t)/59;
  return distance;
}
