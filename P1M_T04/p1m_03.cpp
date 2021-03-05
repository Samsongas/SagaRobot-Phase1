#include "p1m_01.hpp"
#include "p1m_03.hpp"
#include "p1m_05.hpp"
#include "p1m_06.hpp"

/*
 * Checks if straight movement is needed.
 * Checks rotation of robot in corridor.
 * Corrects the rotation if necessary.
 * Advances in a straight line.
 */
void straight_line_movement()
{
  /* Scan the distance of all sensors */
  unsigned s1d, s2d, s3d, s4d;
  s1d = distance_sensor(1);
  delay(5);
  s2d = distance_sensor(2);
  delay(5);
  s3d = distance_sensor(3);
  delay(5);
  s4d = distance_sensor(4);
  delay(5);
  /* Calculate side_distance */
  unsigned side_distance = (s3d + s4d)/2;
  /* If front distance is more than 150mm
   * AND side distance is less than the defined
   */
  if (s1d > 150 && s2d > 150 &&
      s3d < SIDE_DISTANCE && s4d < SIDE_DISTANCE)
  {
    /* Call P1M_05 to get rotation R radians */
    float rot = get_rotation(s3d, s4d);
    /* If P1M_05 returns a rotation */
    if (rot != 0.0)
    {
      /* If the rotation is in range (pi/6, 0) */
      if (rot < M_PI/6 && rot > 0.0)
      {
        /* Advance with a rotation of -10/24 rad/m */
        call_PID(MAX_SPEED, MAX_SPEED*DIFF_DRV, 0, 0);
      }
      /* If the rotation is in range (-pi/6, 0) */
      else if (rot > -M_PI/6 && rot < 0.0)
      {
        /* Advance with a rotation of 10/24 rad/m */
        call_PID(MAX_SPEED*DIFF_DRV, MAX_SPEED, 0, 0);
      }
      /* If the rotation is not in range (-pi/6, pi/6) */
      else
      {
        /* Call PID to stop */
        call_PID(0, 0, 0, 0);
        /* Call PID to turn R radians */
        unsigned gaps = rot*GAPS_PER_RAD/2;
        if (rot > 0)
        {
          call_PID(MAX_SPEED, -MAX_SPEED, gaps, gaps);
        }
        else
        {
          call_PID(-MAX_SPEED, MAX_SPEED, gaps, gaps);
        }
        /* Call PID to advance */
        call_PID(MAX_SPEED, MAX_SPEED, 0, 0);
      }
    }
    /* If rotation is zero */
    else
    {
      /* If the side distance is greater to 250mm */
      if (side_distance > 250)
      {
        /* Advance with a rotation of -10/24 rad/m */
        call_PID(MAX_SPEED, MAX_SPEED*DIFF_DRV, 0, 0);
      }
      /* Else if the side distance is lower than 150mm */
      else if (side_distance < 150)
      {
        /* Advance with a rotation of 10/24 rad/m */
        call_PID(MAX_SPEED*DIFF_DRV, MAX_SPEED, 0, 0);
      }
      /* Else if the side distance is in range [150, 250] */
      else
      {
        /* Advance straight */
        call_PID(MAX_SPEED, MAX_SPEED, 0, 0);
      }
    }
  }
}
