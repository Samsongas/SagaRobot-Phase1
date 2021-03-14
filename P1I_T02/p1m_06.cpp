#include "p1m_06.hpp"
#include "p1m_02.hpp"
#include "p1m_07.hpp"

#define Sample_Time 50

unsigned long PreviousTimeL = 0;
unsigned long PreviousTimeR = 0;

float Ki = Default_Ki;
float Kd = Default_Kd;
float Kp = Default_Kp;

float motorL = 0;
float motorR = 0;

/**
    @brief General PID implementation.
    @param DesiredValue, Value that you want to achieve.
    @param ActualValue, Value got from the sensor.

*/
float PID(float DesiredValue, float ActualValue, byte LeftOrRight)
{
  long unsigned PreviousTime;
  if (LeftOrRight == LEFT_MOTOR) {
    PreviousTime = PreviousTimeL;
  }
  else {
    PreviousTime = PreviousTimeR;
  }
  long unsigned ActualTime = millis();

  float error;
  if (ActualValue == 0)
  {
    error = 1;
  }
  else
  {
    error = DesiredValue/ActualValue - 1;
  }
  float derror = error / float(ActualTime - PreviousTime);
  float ierror = error * float(ActualTime - PreviousTime);
  
  if (LeftOrRight == LEFT_MOTOR) {
    PreviousTimeL = ActualTime;
  }
  else {
    PreviousTimeR = ActualTime;
  }

  return error;
  
//  float PID_Output = (Kp * error + Ki * ierror + Kd * derror);
// 
//  if (PID_Output > PWM_MAX)
//  {
//    PID_Output = PWM_MAX;
//  }
//  else if (PID_Output < 0.1)
//  {
//    PID_Output = 0.1;
//  }
//  else
//  {
//    // MISRA C++ 2008
//  }
//    
//  return PID_Output;
}

/* Set speed and direction,
   needed because encoder don't give us direction.
   Used to don't repeat code.
*/
void set_speed_direction(float dsmL, float dsmR)
{
  /* Get the actual speed in cm/s from the encoder and
   * convert to rad/s */
  float asmL = GetSpeed(ENC_L);
  float asmR = GetSpeed(ENC_R);

  // DEBUG
  Serial.print("\nSpeed of the motors:\n");
  Serial.print(asmL);
  Serial.print(" ");
  Serial.print(asmR);
  Serial.print("\nDesired speed of the motors:\n");
  Serial.print(dsmL);
  Serial.print(" ");
  Serial.print(dsmR);

  motorL += PID(abs(dsmL), asmL, LEFT_MOTOR);
  motorR += PID(abs(dsmR), asmR, RIGHT_MOTOR);

  if(motorL>1)
    motorL = 1;
  if(motorR>1)
    motorR = 1;
  if(motorL<=0)
    motorL = 0;
  if(motorR<=0)
    motorR = 0;

  // DEBUG
  Serial.print("\nAcceleration to the motors:\n");
  Serial.print(motorL);
  Serial.print(" ");
  Serial.print(motorR);

  Serial.print("\n");
  Serial.flush();
  
  if(dsmL == 0){
    motorL = 0;
  }
  if(dsmR ==0){
    motorR = 0;
  }

  if (dsmL >= 0 && dsmR >= 0)
  {
    set_speed(motorL, motorR);
  }
  else if (dsmL <= 0 && dsmR >= 0)
  {
    set_speed(-motorL, motorR);
  }
  else if (dsmL >= 0 && dsmR <= 0)
  {
    set_speed(motorL, -motorR);
  }
  else if (dsmL <= 0 && dsmR <= 0)
  {
    set_speed(-motorL, -motorR);
  }
}
/**
    @brief Set the motor to the desired speed and distance
    unless distance it's 0, then it works indefinitely.
    @param dsmL, Desired speed motor Left.
    @param dsmR, Desired speed motor Right.
    @param ddmL, Desired  distance motor Left.
    @param ddmR, Desired  distance motor Right.


*/
void call_PID(float dsmL, float dsmR, unsigned ddmL, unsigned ddmR)
{
  int sgmL = GetGapCnt(ENC_L); // Starting gaps motor Left and right
  int sgmR = GetGapCnt(ENC_R);

  unsigned attempts = 0;
  unsigned lastGapCnt;

  if (ddmL == 0 && ddmR == 0)
  { // Set only speed and no distance.
    set_speed_direction(dsmL, dsmR);
  }
  else
  {
    while (attempts < 10 && ((int)ddmL + sgmL - (int)GetGapCnt(ENC_L) > 0) && ((int)ddmR + sgmR - (int)GetGapCnt(ENC_R) > 0)) //move at desired speed while distance is not reached
    {
      if (GetGapCnt(ENC_L) + GetGapCnt(ENC_R) == lastGapCnt)
        attempts++;
      set_speed_direction(dsmL, dsmR);
      lastGapCnt = GetGapCnt(ENC_L) + GetGapCnt(ENC_R);
    }
    while (attempts < 10 && ((int)ddmR + sgmR - (int)GetGapCnt(ENC_R) > 0)) // End right motor
    {
      if (GetGapCnt(ENC_R) == lastGapCnt)
        attempts++;
      set_speed_direction(0, dsmR);
      lastGapCnt = GetGapCnt(ENC_R);
    }
    while (attempts < 10 && ((int)ddmL + sgmL - (int)GetGapCnt(ENC_L) > 0)) // End left motor
    {
      if (GetGapCnt(ENC_L) == lastGapCnt)
        attempts++;
      set_speed_direction(dsmL, 0);
      lastGapCnt = GetGapCnt(ENC_L);
    }
    set_speed_direction(0, 0); //STOP
  }
}
/**
    @brief Set the PID parameters.
    @note Future revision could incorpore differente parameters for each component.
    @param ki, Integral gain.
    @param kd, Derivative gain.
    @param kp, Proporcional gain.

*/
void SetPIDparameter(float ki, float kd, float kp)
{
  Ki = ki;
  Kd = kd;
  Kp = kp;
}
