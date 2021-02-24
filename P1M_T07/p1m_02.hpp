
/* DUMMY 
 *For testing purpose 
 */

#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define ENC_L  0
#define ENC_R  1

#define SAMPLE_TIME 100  // in ms

/* Prototypes */
/* Unused
 * void initialize_p1m_02();
 * void EnableGapsCnt(byte LeftorRight);
 * void DisableGapsCnt(byte LeftorRight);
*/
unsigned TestGapCntL = 0;
unsigned TestGapCntR = 0;
unsigned currentTimeL = 0;
unsigned currentTimeR = 0;
unsigned lastTimeL = 0;
unsigned lastTimeR = 0;

unsigned GetGapCnt(byte LeftorRight){
  if (LeftorRight==ENC_L)
  {
    TestGapCntL++;
  return TestGapCntL;
  }
    TestGapCntR++;
  return TestGapCntR;
}
double GetSpeed(byte LeftorRight){
  // Constant for testing purpouse.
  return 17;
}

#endif /* P1M_02_H */
