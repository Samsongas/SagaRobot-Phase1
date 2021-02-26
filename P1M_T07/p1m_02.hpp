
/* DUMMY 
 *For testing purpose 
 */

#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define ENC_L  0
#define ENC_R  1

#define SAMPLE_TIME 100  // in ms

unsigned TestGapCntL = 0;
unsigned TestGapCntR = 0;


unsigned GetGapCnt(byte LeftorRight){
  if (LeftorRight==ENC_L)
  {
    TestGapCntL++;
    Serial.print("\n Left Enc gaps: ");
    Serial.print(TestGapCntL);
    return TestGapCntL;
  }else{
    TestGapCntR++;
    Serial.print("\n Right Enc gaps: ");
    Serial.print(TestGapCntR);
  return TestGapCntR;
  }
}
double GetSpeed(byte LeftorRight){
  // Constant for testing purpouse.
  return 17;
}

#endif /* P1M_02_H */
