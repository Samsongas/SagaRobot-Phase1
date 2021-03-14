#include "p1m_07.hpp"

/* 
 * Initializes all the pins to their
 * corresponding modes.
 */
void initialize_p1m_07()
{
  /* Wheel direction pins */
  pinMode(RIGHT_FW, OUTPUT);
  pinMode(RIGHT_BW, OUTPUT);
  pinMode(LEFT_FW, OUTPUT);
  pinMode(LEFT_BW, OUTPUT);

  /* Wheel acceleration pins */
  pinMode(RIGHT_ACC, OUTPUT);
  pinMode(LEFT_ACC, OUTPUT);

  /* Everything initialized at zero */
  digitalWrite(RIGHT_FW, LOW);
  digitalWrite(RIGHT_BW, LOW);
  digitalWrite(LEFT_FW, LOW);
  digitalWrite(LEFT_BW, LOW);

  analogWrite(RIGHT_ACC, 0);
  analogWrite(LEFT_ACC, 0);
}

/*
 * Gives the motors the desired acceleration,
 * expressed in percentage [0.0, 1.0]
 */
float set_speed(float motorL, float motorR)
{
  /* If acceleration of left motor is positive */
  if (motorL > 0)
  {
    /* Accelerate forward */
    digitalWrite(LEFT_FW, HIGH);
    digitalWrite(LEFT_BW, LOW);
    analogWrite(LEFT_ACC, PWM_MAX/2 + (int(motorL*PWM_MAX)/2)*SPEED_RED);
  }
  /* If acceleration of left motor is negative */
  else if (motorL < 0)
  {
    /* Accelerate backward */
    digitalWrite(LEFT_FW, LOW);
    digitalWrite(LEFT_BW, HIGH);
    analogWrite(LEFT_ACC, PWM_MAX/2 + (abs(int(motorL*PWM_MAX))/2)*SPEED_RED);
  }
  /* In any other case */
  else
  {
    /* Stop the motor */
    digitalWrite(LEFT_FW, LOW);
    digitalWrite(LEFT_BW, LOW);
    analogWrite(LEFT_ACC, 0);
  }

  /* If acceleration of right motor is positive */
  if (motorR > 0)
  {
    /* Accelerate forward */
    digitalWrite(RIGHT_FW, HIGH);
    digitalWrite(RIGHT_BW, LOW);
    analogWrite(RIGHT_ACC, PWM_MAX/2 + (int(motorR*PWM_MAX)/2)*SPEED_RED);
  }
  /* If acceleration of right motor is negative */
  else if (motorR < 0)
  {
    /* Accelerate backward */
    digitalWrite(RIGHT_FW, LOW);
    digitalWrite(RIGHT_BW, HIGH);
    analogWrite(RIGHT_ACC, PWM_MAX/2 + (abs(int(motorR*PWM_MAX))/2)*SPEED_RED);
  }
  /* In any other case */
  else
  {
    /* Stop the motor */
    digitalWrite(RIGHT_FW, LOW);
    digitalWrite(RIGHT_BW, LOW);
    analogWrite(RIGHT_ACC, 0);
  }
    
}
