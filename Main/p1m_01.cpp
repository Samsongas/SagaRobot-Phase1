#include "p1m_01.hpp"

/* Calibration */
long int difference = 0;

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

  difference = distance_sensor(3) - distance_sensor(4);
}

/*
 * Receives the as input a sensor.
 * Returns distance of obstacle detected
 * by sensor, in mm.
 */
long unsigned distance_sensor(int sensor){
  /* Variable to store the distance */
  long unsigned distance = 0;
  /* For an oversampling of 5 */
  for(int i=0; i<5; i++)
  {
    /* Send a 10 us pulse trough trigger pin */
    digitalWrite(TRG, HIGH);
    delayMicroseconds(10); //10us pulse
    digitalWrite(TRG, LOW);
    /* Read the width of the pulse sent
       by the sensor */
    unsigned long t = 0;
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
    /* If distance did not reach a max */
    if (distance < 99999)
    {
      /* Set a new value */
      distance += (10*t)/59; 
    }
    delay(1);
  }
  /* Return variable with distances stored reverting oversampling */
  return sensor == 4? distance/5 + difference: distance/5;
}
