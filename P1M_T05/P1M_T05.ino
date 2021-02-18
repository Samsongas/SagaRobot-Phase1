#include "p1m_04.hpp"

void setup() {
  
  // Initialize Serial
  Serial.begin(9600);
  delay(3000);
  
  // Test 1
  Serial.print("\nTest 1:\n");
  rotation_movement();
  delay(1000);

  // Test 2
  Serial.print("\nTest 2:\n");
  rotation_movement();
  delay(1000);

  // Test 3
  Serial.print("\nTest 3:\n");
  rotation_movement();
  delay(1000);
   
}

void loop() {
  // None
}
