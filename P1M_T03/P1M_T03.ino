#include "p1m_02.hpp"
void setup() {
  initialize_p1m_02();
  EnableGapsCnt(Left_Motor);
  EnableGapsCnt(Right_Motor);
  Serial.begin(115200);
}

void loop() {

  // LeftEncoder


  GetGapCnt(Right_Motor);
  GetSpeed(Right_Motor);

  // RightEncoder

  GetGapCnt(Left_Motor);
  GetSpeed(Left_Motor);
  Serial.print("Left gap count ");
  Serial.print(GetGapCnt(Left_Motor));
  Serial.print(",");

  Serial.print("Right gap count ");
  Serial.print(GetGapCnt(Right_Motor));
  Serial.print(",");

  Serial.print("Left speed count ");
  Serial.print(GetSpeed(Left_Motor));
  Serial.print(",");

  Serial.print("Right speed count ");
  Serial.print(GetSpeed(Right_Motor));
  Serial.print("\r\n");
  delay(500);
}
