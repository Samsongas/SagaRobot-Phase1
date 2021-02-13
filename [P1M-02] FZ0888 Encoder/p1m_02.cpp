#include "p1m_02.h"

// Global variables

    encoder EncoderR = {0};
    encoder EncoderL = {0};

/**
  * @brief Initializes pins and interrupt.
  *
  * @note  Two interrups are needed
  *
  */

void initialize_p1m_01(){

    // set pin mode
	pinMode(R_D0, INPUT);
	pinMode(L_D0, INPUT);

    // Set interrupt
    attachInterrupt(digitalPinToInterrupt(L_DO), ISR_speed_sensor(&EncoderL), RISING);
    attachInterrupt(digitalPinToInterrupt(R_DO), ISR_speed_sensor(&EncoderR), RISING);

}

/**
  * @brief Interruption rutine service, calculate the current speed of the wheel.
  *
  * @note  
  *
  * @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
  *
  */

void ISR_speed_sensor(encoder *encoder){

    unsigned CurrentTime = millis();
    if(encoder->EnableGaps) encoder->GapCount++;
    encoder->speed = (1/20)*2*M_PI/(CurrentTime - encoder->LastTime);
    LastTime = CurrentTime;

}
/**
  * @brief Return encoder last calculated speed.
  *
  * @note  
  *
  * @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
  *
  * @retval speed on RPM calculated by the encoder selected.
  */

double GetSpeed(encoder *encoder){
    return encoder.speed;
}
/**
  * @brief Return encoder last calculated speed.
  *
  * @note  
  *
  * @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
  *
  * @retval Number of gaps counted for the selected encoder.
  */

double GetGapCnt(encoder *encoder){
    return encoder->GapCount;
}
/**
  * @brief Enable gaps counting for the selected encoder.
  *
  * @note  
  *
  * @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
  *
  */

void EnableGapsCnt(encoder *encoder){
    encoder->EnableGaps = TRUE;
}

/**
  * @brief Disable gaps counting for the selected encoder.
  *
  * @note  
  *
  * @param *encoder, pointer to the encoder struct variable corresponding with the encoder selected.
  *
  */
void DisabeGapsCnt(encoder *encoder){
    encoder->EnableGaps = FALSE;
}