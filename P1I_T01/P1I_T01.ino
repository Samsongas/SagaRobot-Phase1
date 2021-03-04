#include "p1m_01.hpp"
#include "p1m_03.hpp"
#include "p1m_04.hpp"
#include "p1m_05.hpp"

void setup() {
  Serial.begin(9600);
  /* Initialization of the pins */
  initialize_p1m_01();
  /* Test steps */
  Serial.print("Step 1\n");
  Serial.print(
  "Situate the robot in a straight corridor, just in the middle.\n");
  Serial.print("Step 2\n");
  Serial.print(
  "Situate the robot in a straight corridor, 50mm from the left wall.\n"
  Serial.print("Step 3\n");
  Serial.print(
  "Situate the robot in a straight corridor, 50mm from the right wall.\n"
  Serial.print("Step 4\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of 𝝅/3\n"
  Serial.print("Step 5\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of -𝝅/3\n"
  Serial.print("Step 6\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of 𝝅/10\n"
  Serial.print("Step 7\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of -𝝅/10\n"
  Serial.print("Step 8\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a gap at the left.\n"
  Serial.print("Step 9\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a gap at the left and an obstacle in front.\n"
  Serial.print("Step 10\n");
  Serial.print(
  "Situate the robot in a straight corridor, with an obstacle in front.\n"
}

void loop() {
  // None
}