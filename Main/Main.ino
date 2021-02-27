#include "p1m_01.hpp"
#include "p1m_02.hpp"
#include "p1m_03.hpp"
#include "p1m_04.hpp"

void setup() {
  Serial.begin(9600);
  initialize_p1m_01();
  initialize_p1m_02();
  EnableGapsCnt(ENC_L);
  EnableGapsCnt(ENC_R);

}

void loop() {
  straight_line_movement();
  Serial.print("\nLeft:");
  Serial.print(GetSpeed(ENC_L));
  Serial.print("\nRight:");
  Serial.print(GetSpeed(ENC_R));
  Serial.print("\n");
  //rotation_movement();
}
