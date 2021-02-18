/*
 * Dummy for testing purposes
 */

#ifndef P1M_06_H
#define P1M_06_H

#include <Arduino.h>

/*
 * Dummy for testing P1M_T04
 * Serial communication must be initialized.
 */
void call_PID(float dsmL, float dsmR,
              unsigned ddmL, unsigned ddmR)
{
  Serial.print("\ncall_PID:");
  Serial.print("\nDesired speed motor L: ");
  Serial.print(dsmL);
  Serial.print("\nDesired speed motor R: ");
  Serial.print(dsmR);
  Serial.print("\nDesired distance motor L: ");
  Serial.print(ddmL);
  Serial.print("\nDesired distance motor R: ");
  Serial.print(ddmR);
  Serial.print("\n");
}

#endif /* P1M_06_H */
