#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define ENC_L  0
#define ENC_R  1

#define SAMPLE_TIME 50  // in ms

/* 
 * Number of GAPS per radian
 * (distance_between_wheels/2) / (pi*wheel_diameter/gaps_per_turn)
 */
#define GAPS_PER_RAD (0.13/2)/(M_PI*0.07/20)

/* Prototypes */

void initialize_p1m_02();
void EnableGapsCnt(byte encoder_lr);
void DisableGapsCnt(byte encoder_lr);
unsigned GetGapCnt(byte encoder_lr);
double GetSpeed(byte encoder_lr);

#endif /* P1M_02_H */
