#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define ENC_L  0
#define ENC_R  1

#define SAMPLE_TIME 100  // in ms

/* Prototypes */

void initialize_p1m_02();
void EnableGapsCnt(byte LeftorRight);
void DisableGapsCnt(byte LeftorRight);
unsigned GetGapCnt(byte LeftorRight);
double GetSpeed(byte LeftorRight);

#endif /* P1M_02_H */
