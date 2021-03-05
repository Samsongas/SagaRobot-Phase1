#include "p1m_01.hpp"

void setup() {
  initialize_p1m_01();
  /* LED to test the distance */
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (distance_sensor(1) < 200)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  Serial.print("\nSensor1:\n");
  Serial.print(distance_sensor(1));
  delay(500);
  Serial.print("\nSensor2:\n");
  Serial.print(distance_sensor(2));
  delay(500);
  Serial.print("\nSensor3:\n");
  Serial.print(distance_sensor(3));
  delay(500);
  Serial.print("\nSensor4:\n");
  Serial.print(distance_sensor(4));
  Serial.flush();
  delay(1000);
}
