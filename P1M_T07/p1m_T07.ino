#include "p1m_06.hpp"

void setup() {
  initialize_p1m_02();
  EnableGapsCnt(&EncoderL);
  EnableGapsCnt(&EncoderR);
  Serial.begin(115200);
}

void loop() {

}
