#include "p1m_02.hpp"

unsigned long CurrentTime = 0;
unsigned long CurrentTime2 = 0;
encoder EncoderR = {0};
encoder EncoderL = {0};
/**
    @brief Interruption rutine service, calculate the current speed of the wheel.

    @note

    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

*/
void ISR_speed_sensor(encoder *encoder)
{

  if (micros() - encoder->LastInterrupt > 500) {

    CurrentTime = micros();
    if (encoder->EnableGaps)
    {
      encoder->GapsCount++;
    }

  } else {
    /* Way too fast since last interrupt, ignore it.
      with a 20 slit disk, and the wheel rotating fast enough to generate interrupts
      at a 500 microsecond intervals, the wheel would have to rotate at 6000 rpm
      = 1/(0.000500sec * 20(slits/rotation)) * 60(seconds/minute)

    */
  }

}

void ISR_speed_sensor_L () {
  ISR_speed_sensor(&EncoderL);
}

void ISR_speed_sensor_R () {
  ISR_speed_sensor(&EncoderR);
}


/**
    @brief Initializes interrupt.

    @note  Two interrups are needed

*/

void initialize_p1m_02()
{

  // Set interrupt
  attachInterrupt(digitalPinToInterrupt(3), ISR_speed_sensor_L, RISING);
  attachInterrupt(digitalPinToInterrupt(2), ISR_speed_sensor_R, RISING);
}


/**
    @brief Return encoder last calculated speed.

    @note

    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

    @retval speed on RPM calculated by the encoder selected.
*/

double GetSpeed(encoder *encoder)
{
  CurrentTime2 = millis();

  double diffTime = CurrentTime2 - encoder->LastTime;
  /*  speed = rotation / time
      rotation = (Current gaps-Last gaps)*1/20
      time = time difference in ms * 1/60.000 min/ms
      speed = 3.000*(Current gaps-Last gaps)/(time difference)
  */
  if (diffTime > SAMPLE_TIME) {

    encoder->WheelSpeed = 3000 * (encoder->GapsCount - encoder->LastGapsCount) / diffTime;
    encoder->LastTime = CurrentTime2;
    Serial.print(encoder->GapsCount - encoder->LastGapsCount);
    Serial.print(",");
    encoder->LastGapsCount = encoder->GapsCount;
    Serial.print(diffTime);
    Serial.print("\r\n");
  }
  return encoder->WheelSpeed;

}
/**
    @brief Return encoder last calculated speed.

    @note

    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

    @retval Number of gaps counted for the selected encoder.
*/

unsigned GetGapCnt(encoder *encoder)
{
  return encoder->GapsCount;
}
/**
    @brief Enable gaps counting for the selected encoder.

    @note

    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

*/

void EnableGapsCnt(encoder *encoder)
{
  encoder->EnableGaps = true;
}

/**
    @brief Disable gaps counting for the selected encoder.

    @note

    @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.

*/
void DisabeGapsCnt(encoder *encoder)
{
  encoder->EnableGaps = false;
  encoder->GapsCount = 0;
}
