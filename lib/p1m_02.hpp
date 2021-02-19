#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define SAMPLE_TIME 100
/**
  * @brief Store usefull information for each encoder.
  *
  * @note  
  *
  * @param speed Last speed in RPM measured by the encoder.
  *
  * @param LastTime Value of the timer the last time it was called.
  * 
  * @param EnabeGaps Boolean to decide if the caps are counted.
  * 
  * @param GapCount  Number of gaps counted since enabling.
  */

struct encoder{
    double WheelSpeed;
    unsigned long LastTime;
    unsigned long LastInterrupt;
    bool EnableGaps;
    volatile unsigned long GapsCount;
    unsigned long LastGapsCount;
};

// Global variables

    extern encoder EncoderR;
    extern encoder EncoderL;


/* Prototypes */

void initialize_p1m_02();
void EnableGapsCnt(encoder *encoder);
void DisabeGapsCnt(encoder *encoder);
unsigned GetGapCnt(encoder *encoder);
double GetSpeed(encoder *encoder);

#endif /* P1M_02_H */
