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
  /* Scan the distance of all sensors */
  unsigned s1d, s2d, s3d, s4d;
  s1d = distance_sensor(1);
  s2d = distance_sensor(2);
  s3d = distance_sensor(3);
  s4d = distance_sensor(4);
  /* Move */
  straight_line_movement(s1d, s2d, s3d, s4d);
  rotation_movement(s1d, s2d, s3d, s4d);
}
