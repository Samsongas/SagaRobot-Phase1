#include "p1m_01.hpp"
#include "p1m_02.hpp"
#include "p1m_03.hpp"
#include "p1m_04.hpp"
#include "p1m_07.hpp"

void setup() {
  Serial.begin(9600);
  initialize_p1m_01();
  initialize_p1m_02();
  initialize_p1m_07();
  EnableGapsCnt(ENC_L);
  EnableGapsCnt(ENC_R);

}

void loop() {
  straight_line_movement();
  rotation_movement();
}
