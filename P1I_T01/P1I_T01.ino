#include "p1m_01.hpp"
#include "p1m_03.hpp"
#include "p1m_04.hpp"
#include "p1m_05.hpp"

/* Time between tests */
#define DELAY 10000

void setup() {
  Serial.begin(9600);
  /* Initialization of the pins */
  initialize_p1m_01();

  /* 
   * Test style 1:
   * Consists in changing the position of the robot
   * and reading a single result. Test style 2 is
   * available in loop function.
   */
  /* Test steps */
  /* Selected test style 2, uncomment for selecting style 1
  delay(DELAY);
  Serial.print("Step 1\n");
  Serial.print(
  "Situate the robot in a straight corridor, just in the middle.\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 2\n");
  Serial.print(
  "Situate the robot in a straight corridor, 50mm from the left wall.\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 3\n");
  Serial.print(
  "Situate the robot in a straight corridor, 50mm from the right wall.\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 4\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of 𝝅/3\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 5\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of -𝝅/3\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 6\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of 𝝅/10\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 7\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a deviation of -𝝅/10\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 8\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a gap at the left.\n");
  delay(DELAY);
  Serial.flush();
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 9\n");
  Serial.print(
  "Situate the robot in a straight corridor, with a gap at the left and an obstacle in front.\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  
  Serial.print("Step 10\n");
  Serial.print(
  "Situate the robot in a straight corridor, with an obstacle in front.\n");
  Serial.flush();
  delay(DELAY);
  straight_line_movement();
  rotation_movement();
  Serial.flush();
  */
}

void loop() {
  /* Scan the distance of all sensors */
  unsigned s1d, s2d, s3d, s4d;
  s1d = distance_sensor(1);
  s2d = distance_sensor(2);
  s3d = distance_sensor(3);
  s4d = distance_sensor(4);
  /* Move */
  straight_line_movement(s1d, s2d, s3d, s4d);
  rotation_movement(s1d, s2d, s3d, s4d);
  delay(1000);
  Serial.flush();
}
