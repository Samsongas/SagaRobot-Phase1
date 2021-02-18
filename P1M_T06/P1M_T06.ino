#include "p1m_05.hpp"


void setup() {

  float value;
  
  // Initialize Serial
  Serial.begin(9600);
  delay(3000);
  
  // Test 1
  Serial.print("\nTest 1:\n");
  Serial.print("Sending { 150, 159}...\n");
  value = get_rotation(150, 159);
  delay(1000);
  Serial.print("Received ");
  Serial.print(value);
  Serial.print("\n");

  // Test 2
  Serial.print("\nTest 2:\n");
  Serial.print("Sending { 230, 140}...\n");
  value = get_rotation(230, 140);
  delay(1000);
  Serial.print("Received ");
  Serial.print(value);
  Serial.print("\n");

  // Test 3
  Serial.print("\nTest 3:\n");
  value;
  Serial.print("Sending { 140, 230}...\n");
  value = get_rotation(140, 230);
  delay(1000);
  Serial.print("Received ");
  Serial.print(value);
  Serial.print("\n");
   
}

void loop() {
  // None
}
