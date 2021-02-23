#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define Left_Motor 0
#define Right_Motor 1

#define SAMPLE_TIME 100  // in ms
/**
    @brief Store usefull information for each encoder.

    @note

    @param WheelSpeed Last speed in RPM measured by the encoder.

    @param LastTime Value of the timer the last time it was called.

    @param LastInterrupt Value to keep trace of the last interrupt and avoid rebounce.

    @param EnabeGaps Boolean to decide if the caps are counted.

    @param GapsCount  Number of gaps counted since enabling.

    @param LastGapsCount Number of gaps counted at the starting of GetSpeed function.
*/




/* Prototypes */

void initialize_p1m_02();
void EnableGapsCnt(byte LeftorRight);
void DisabeGapsCnt(byte LeftorRight);
unsigned GetGapCnt(byte LeftorRight);
double GetSpeed(byte LeftorRight);

#endif /* P1M_02_H */
