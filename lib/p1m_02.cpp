#include "p1m_02.hpp"

////////////////////////////////////////
//            VARIABLES               //
////////////////////////////////////////
unsigned long CurrentTime = 0;
unsigned long CurrentTime2 = 0;

/**
    @brief Store usefull information for each encoder.
    @param WheelSpeed Last speed in RPM measured by the encoder.
    @param LastTime Value of the timer the last time it was called.
    @param LastInterrupt Value to keep trace of the last interrupt and avoid rebounce.
    @param EnabeGaps Boolean to decide if the caps are counted.
    @param GapsCount Number of gaps counted since enabling.
    @param LastGapsCount Number of gaps counted at the starting of GetSpeed function.
*/

struct encoder
{
  double WheelSpeed;
  unsigned long LastTime;
  unsigned long LastInterrupt;
  bool EnableGaps;
  volatile unsigned long GapsCount;
  unsigned long LastGapsCount;
};

encoder EncoderR = {0};
encoder EncoderL = {0};

////////////////////////////////////////
//   INTERNAL FUNCTIONS               //
////////////////////////////////////////

/**
    @brief Interruption rutine service, calculate the current speed of the wheel.
    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

*/
void ISR_speed_sensor_int(encoder *encoder)
{
  /* If Gaps counting is enabled */
  if (encoder->EnableGaps)
  {
    if (micros() - encoder->LastInterrupt > 5000)
    {
  
      encoder->LastInterrupt = micros();
      if (encoder->EnableGaps)
      {
        encoder->GapsCount++;
      }
    }
    else
    {
      /* Way too fast since last interrupt, ignore it.
        with a 20 slit disk, and the wheel rotating fast enough to generate interrupts
        at a 500 microsecond intervals, the wheel would have to rotate at 6000 rpm
        = 1/(0.000500sec * 20(slits/rotation)) * 60(seconds/minute)
      */
    }
  }
  /* In any other case */
  else
  {
    /* Set the Gap counter to zero */
    encoder->GapsCount = 0;
  }
}


/**
    @brief Initializes interrupt.
    @note  Two interrups are needed
*/
void ISR_speed_sensor_L()
{
  ISR_speed_sensor_int(&EncoderL);
}

void ISR_speed_sensor_R()
{
  ISR_speed_sensor_int(&EncoderR);
}




/**
    @brief Return encoder last calculated speed.
    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
    @retval speed on RPM calculated by the encoder selected.
*/

double GetSpeed_int(encoder *encoder)
{
  CurrentTime2 = millis();

  double diffTime = CurrentTime2 - encoder->LastTime;
  /*  speed = rotation / time
      rotation = (Current gaps-Last gaps)/gaps per radian
      time = time difference in ms * 1/60.000 min/ms
      speed = 60.000*(Current gaps-Last gaps)/(gaps per radian * time difference)
  */
  if (diffTime > SAMPLE_TIME)
  {

    //encoder->WheelSpeed = 60000 * float(encoder->GapsCount - encoder->LastGapsCount) / (GAPS_PER_RAD * diffTime);
    /* Debug tuning */
    encoder->WheelSpeed = 600 * float(encoder->GapsCount - encoder->LastGapsCount) / (GAPS_PER_RAD * diffTime);
    encoder->LastTime = CurrentTime2;
    encoder->LastGapsCount = encoder->GapsCount;

  }
  return encoder->WheelSpeed;
}
/**
    @brief Return encoder last calculated speed.
    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
    @retval Number of gaps counted for the selected encoder.
*/

unsigned GetGapCnt_int(encoder *encoder)
{
  return encoder->GapsCount;
}
/**
    @brief Enable gaps counting for the selected encoder.
    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
*/

void EnableGapsCnt_int(encoder *encoder)
{
  encoder->EnableGaps = true;
}

/**
    @brief Disable gaps counting for the selected encoder.
    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
*/
void DisabeGapsCnt_int(encoder *encoder)
{
  encoder->EnableGaps = false;
}
////////////////////////////////////////
//            USER API                //
////////////////////////////////////////

void initialize_p1m_02()
{
  // Set interrupt
  attachInterrupt(digitalPinToInterrupt(3), ISR_speed_sensor_L, RISING);
  attachInterrupt(digitalPinToInterrupt(2), ISR_speed_sensor_R, RISING);
}

void EnableGapsCnt(byte encoder_lr)
{
  if(encoder_lr == ENC_L)
  {
     return EnableGapsCnt_int(&EncoderL);
  }
  else
  {
    return EnableGapsCnt_int(&EncoderR);
  }
}
void DisableGapsCnt(byte encoder_lr)
{
  if (encoder_lr == ENC_L)
  {
    return DisabeGapsCnt_int(&EncoderL);
  }
  else
  {
    return DisabeGapsCnt_int(&EncoderR);
  }
}
unsigned GetGapCnt(byte encoder_lr)
{
  if (encoder_lr == ENC_L)
  {
    return GetGapCnt_int(&EncoderL);
  }
  else
  {
    return GetGapCnt_int(&EncoderR);
  }
}
double GetSpeed(byte encoder_lr)
{
  if (encoder_lr == ENC_L)
  {
    return GetSpeed_int(&EncoderL);
  }
  else
  {
    return GetSpeed_int(&EncoderR);
  }
}
