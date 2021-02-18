#include "p1m_02.hpp"
void setup() {
  initialize_p1m_02();
  EnableGapsCnt(&EncoderL);
  EnableGapsCnt(&EncoderR);
  Serial.begin(115200);
}

void loop() {

  // LeftEncoder


  GetGapCnt(&EncoderR);
  GetSpeed(&EncoderR);

  // RightEncoder

  GetGapCnt(&EncoderL);
  GetSpeed(&EncoderL);

  Serial.print(GetGapCnt(&EncoderL));
  Serial.print(",");

  Serial.print(GetGapCnt(&EncoderR));
  Serial.print(",");

  Serial.print(GetSpeed(&EncoderL));
  Serial.print(",");

  Serial.print(GetSpeed(&EncoderR));
  Serial.print("\r\n");
  delay(500);
}
