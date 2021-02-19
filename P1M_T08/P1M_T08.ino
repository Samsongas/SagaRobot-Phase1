#include "p1m_07.hpp"

void setup() {
  initialize_p1m_07();
  delay(1000);
  float cnt = 0.0;
  do
  {
    cnt = cnt+0.1;
    set_speed(cnt, 0.0);
    delay(3000);
  }
  while(cnt<1.0);

  cnt = 0.0;
  do
  {
    cnt = cnt+0.1;
    set_speed(0.0, cnt);
    delay(3000);
  }
  while(cnt<1.0);

  cnt = 0.0;
  do
  {
    cnt = cnt+0.1;
    set_speed(-cnt, -cnt);
    delay(3000);
  }
  while(cnt<1.0);

}

void loop() {
  // None

}
