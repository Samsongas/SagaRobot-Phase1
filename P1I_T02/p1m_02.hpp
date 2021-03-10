#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define ENC_L  0
#define ENC_R  1

#define SAMPLE_TIME 100  // in ms

/* Prototypes */

void initialize_p1m_02();
void EnableGapsCnt(byte encoder_lr);
void DisableGapsCnt(byte encoder_lr);
unsigned GetGapCnt(byte encoder_lr);
double GetSpeed(byte encoder_lr);

#endif /* P1M_02_H */
