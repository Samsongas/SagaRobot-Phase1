#ifndef P1M_02_H
#define P1M_02_H

#include <Arduino.h>

#define R_D0 D2;
#define L_D0 D3;
#define M_PI 3.14159265358979323846

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
    double speed;
    unsigned LastTime;
    bool EnableGaps;
    double GapCount;
}

/* Prototypes */

void initialize_p1m_01();
void ISR_speed_sensor(encoder *encoder);
void EnableGapCnt(encoder *encoder);
void DisabeGapsCnt(encoder *encoder);
double GetGapCnt(encoder *encoder);
double GetSpeed(encoder *encoder);

#endif /* P1M_02_H */