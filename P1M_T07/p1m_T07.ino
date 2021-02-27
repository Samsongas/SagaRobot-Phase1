
#include "p1m_06.hpp"

int ActualValue = 0;
int DesiredValue = 17;
unsigned temp = 0;
void setup() {
  Serial.begin(115200);
#define MAX_SPEED 20
}

void loop() {

  /* TEST 1
     PID Function
  */
  float PID_Output = PID(DesiredValue, ActualValue, LEFT_MOTOR) / 255;
  Serial.print("\n\r");
  Serial.print(PID_Output);
  Serial.print(" , ");
  Serial.print(DesiredValue);
  Serial.print(" , ");
  Serial.print(ActualValue);
  ActualValue += PID_Output;
  delay(100);


  /* END TEST 1 */

  /* TEST 2:
      CALL PID direction
  */
  Serial.print(" \n\r Pos, Pos \n\r" );
  temp = millis();
  while (millis() - temp < 1000) {
    call_PID(100, 100, 0, 0);
    delay(250);
  }
  Serial.print(" \n\r Pos, neg \n\r" );
  temp = millis();
  while (millis() - temp < 1000) {
    call_PID(100, -100, 0, 0);
    delay(250);
  }
  Serial.print(" \n\r Neg, Pos \n\r" );
  temp = millis();
  while (millis() - temp < 1000) {
    call_PID(-100, 100, 0, 0);
    delay(250);
  }
  Serial.print(" \n\r Neg, Neg \n\r" );
  temp = millis();
  while (millis() - temp < 1000) {
    call_PID(-100, -100, 0, 0);
    delay(250);
  }
  Serial.print(" \n\r zero, zero \n\r" );
  temp = millis();
  while (millis() - temp < 1000) {
    call_PID(0, 0, 0, 0);
    delay(250);
  }
  /*  END TEST 2  */

  /* TEST 3:
     DISTANCE
  */
  call_PID(18, 18, 150, 10);
  delay(10000);
  /* END TEST 3*/

}
