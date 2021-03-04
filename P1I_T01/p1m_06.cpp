#include "p1m_06.hpp"

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
