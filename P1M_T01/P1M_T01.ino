#include "p1m_01.hpp"

void setup() {
  initialize_p1m_01();
  /* LED to test the distance */
  pinMode(13, OUTPUT);
}

void loop() {
  if (distance_sensor(1) == 200)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
