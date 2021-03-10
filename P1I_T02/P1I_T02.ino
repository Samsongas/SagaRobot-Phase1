#include "p1m_02.hpp"
#include "p1m_06.hpp"
#include "p1m_07.hpp"

#define WAIT_TIME 3000

void setup() {
  Serial.begin(9600);
  initialize_p1m_02();
  initialize_p1m_07();
  EnableGapsCnt(ENC_L);
  EnableGapsCnt(ENC_R);

}

void loop() {
  Serial.print("\nTest Step 1:");
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋, 0, 0}");
  call_PID(2*M_PI,2*M_PI,0,0);
  delay(WAIT_TIME);
  Serial.print("\nTest Step 2:");
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋*0.976, 0, 0}");
  call_PID(2*M_PI,2*M_PI*0.976,0,0);
  delay(WAIT_TIME);
  Serial.print("\nTest Step 3:");
  Serial.print("\nPID called with values { 2*𝜋*0.976, 2*𝜋, 0, 0}");
  call_PID(2*M_PI*0.976,2*M_PI,0,0);
  delay(WAIT_TIME);
  Serial.print("\nTest Step 4:");
  Serial.print("\nPID called with values { 0, 0, 0, 0}");
  call_PID(0,0,0,0);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { 2*𝜋, -2*𝜋, 6, 6}");
  call_PID(2*M_PI,-2*M_PI,6,6);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋, 0, 0}");
  call_PID(2*M_PI,2*M_PI,0,0);
  delay(WAIT_TIME);
  Serial.print("\nTest Step 5:");
  Serial.print("\nPID called with values { 0, 0, 0, 0}");
  call_PID(0,0,0,0);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { -2*𝜋, 2*𝜋, 6, 6}");
  call_PID(-2*M_PI,2*M_PI,6,6);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋, 0, 0}");
  call_PID(2*M_PI,2*M_PI,0,0);
  delay(WAIT_TIME);
  Serial.print("\nTest Step 6:");
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋, 11, 11}");
  call_PID(2*M_PI,2*M_PI,11,11);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { 2*𝜋, -2*𝜋, 9, 9}");
  call_PID(2*M_PI,-2*M_PI,9,9);
  delay(WAIT_TIME);
  Serial.print("\nPID called with values { 2*𝜋, 2*𝜋, 27, 27}");
  call_PID(2*M_PI,2*M_PI,27,27);
  delay(WAIT_TIME);
}
