#include "p1m_03.hpp"

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  delay(2000);
  Serial.print("\nTest 1.1\n");
  straight_line_movement();
  delay(2000);
  Serial.print("\nTest 1.2\n");
  straight_line_movement();
  delay(2000);
  Serial.print("\nTest 2.1\n");
  straight_line_movement();
  delay(2000);
  Serial.print("\nTest 2.2\n");
  straight_line_movement();
  delay(2000);
  Serial.print("\nTest 2.3\n");
  straight_line_movement();
}

void loop() {
  // None

}
