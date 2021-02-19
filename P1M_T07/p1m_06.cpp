#include "p1m_06.hpp"

#define Sample_Time 50

unsigned long ActualTime = 0;
unsigned long PreviousTime = 0;
float PID_Output = 0;
float Ki = Default_Ki; 
float Kd = Default_Kd; 
float Kp = Default_Kp;

/**
    @brief General PID implementation.

    @note

    @param DesiredValue, Value that you want to achieve.

    @param ActualValue, Value gotten from the sensor.

*/
float PID(float DesiredValue, float ActualValue)
{

    ActualTime = millis();
    if (ActualTime - PreviousTime > Sample_Time)
    {
        float error = DesiredValue - ActualValue;
        float derror = error / (ActualTime - PreviousTime);
        float ierror = error * (ActualTime - PreviousTime);
        PreviousTime = ActualTime;
        PID_Output = Kp * error + Ki * ierror + Kd * derror;
        if (PID_Output > PWM_MAX)
        {
            return PWM_MAX;
        }
    }
    return PID_Output;
}
/**
    @brief Set the motor to the desired speed and distance 
    unless distance it's 0, then it works indefinitely.
    @note

    @param dsmL, Desired speed motor Left.

    @param dsmR, Desired speed motor Right.

    @param ddmL, Desired speed distance Left.

    @param ddmR, Desired speed distance Right.


*/
void call_PID(float dsmL, float dsmR, unsigned ddmL, unsigned ddmR)
{
    float asmL = GetSpeed(&EncoderL);       // actual speed motor left.
    float asmR = GetSpeed(&EncoderR);
    unsigned adsmL = GetGapCnt(&EncoderL);  // actual gaps
    unsigned adsmR = GetGapCnt(&EncoderR);
    float motorL = PID(dsmL,asmL)/PWM_MAX;
    float motorR = PID(dsmR,asmR)/PWM_MAX;
    if (dsmL>0 && dsmR>0)
    {
        set_speed(motorL, motorR);
    }
    else if(dsmL<0 && dsmR>0)
    {
        set_speed(-motorL, motorR);
    }
        else if(dsmL>0 && dsmR<0)
    {
        set_speed(motorL, -motorR);
    }
        else if(dsmL<0 && dsmR<0)
    {
        set_speed(-motorL, -motorR);
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
