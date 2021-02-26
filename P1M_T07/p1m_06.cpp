#include "p1m_06.hpp"
#include "p1m_02.hpp"
#include "p1m_07.hpp"

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
        PID_Output = (Kp * error + Ki * ierror + Kd * derror);
        if (PID_Output > PWM_MAX)
        {
            return PWM_MAX;
        }
    }
    return PID_Output;
}

/* Set speed and direction, 
 * needed because encoder don't give us direction.
 * Used to don't repeat code.
 */
void set_speed_direction(float dsmL, float dsmR)
{
    //TODO add the algorithm necesary to only run for the distance desired.
    float asmL = GetSpeed(ENC_L); // get actual speed motor left.
    float asmR = GetSpeed(ENC_R);

    float motorL = PID(abs(dsmL), asmL) / PWM_MAX; // Get PID values
    float motorR = PID(abs(dsmR), asmR) / PWM_MAX;

    if (dsmL > 0 && dsmR > 0)
    {
        set_speed(motorL, motorR);
    }
    else if (dsmL < 0 && dsmR > 0)
    {
        set_speed(-motorL, motorR);
    }
    else if (dsmL > 0 && dsmR < 0)
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
    @note

    @param dsmL, Desired speed motor Left.

    @param dsmR, Desired speed motor Right.

    @param ddmL, Desired  distance motor Left.

    @param ddmR, Desired  distance motor Right.


*/
void call_PID(float dsmL, float dsmR, unsigned ddmL, unsigned ddmR)
{

    unsigned sgmL = GetGapCnt(ENC_L); // Starting gaps motor Left and right
    unsigned sgmR = GetGapCnt(ENC_R);

    if (ddmL == 0 && ddmR == 0)
    { // Set only speed and no distance.
        set_speed_direction(dsmL, dsmR);
    }
    else
    {
        while ((ddmL + sgmL - GetGapCnt(ENC_L) < 0) && (ddmR + sgmR - GetGapCnt(ENC_R) < 0)) //move at desired speed while distance is not reached
        {
            set_speed_direction(dsmL, dsmR);
        }
        if ((ddmL + sgmL - GetGapCnt(ENC_L) == 0) && (ddmR + sgmR - GetGapCnt(ENC_R) < 0)) // If right motor distance is not reached keep moving right motor.
        {
            while ((ddmR + sgmR - GetGapCnt(ENC_R) != 0))
            {
                set_speed_direction(0, dsmR);
            }
        }
        if ((ddmL + sgmL - GetGapCnt(ENC_L) < 0) && (ddmR + sgmR - GetGapCnt(ENC_R) == 0)) // If left motor distance is not reached keep moving left motor.
        {
            while ((ddmR + sgmR - GetGapCnt(ENC_L) < 0))
            {
                set_speed_direction(dsmL, 0);
            }
        }
        set_speed_direction(0, 0); // when both motor has reached the desired distance car should stop.
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
