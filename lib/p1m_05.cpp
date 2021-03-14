#include "p1m_05.hpp"

/*
 * Returns the rotation angle of the robot,
 * given as inputs the distance sensed by
 * sensor 3 and 4 (side sensors).
 */
float get_rotation(unsigned s3d, unsigned s4d)
{
  /* Initial guess is that the robot is straight */
  float angle = 0.0;
  /* If the difference between the distances 
   * given by the sensors is less than 20mm */
  if ( abs(int(s3d) - int(s4d)) > 20 )
  {
    /* If obstacle sensed by sensor 4 is further
     * than the one sensed by sensor 3 */
    if ( s4d > s3d )
    {
    /* Calculate the angle */
    angle = - atan( float(s4d - s3d) / SNS_DST );
    }
    /* In any other case */
    else
    {
    /* Calculate the angle this other way */
    angle = atan( float(s3d - s4d) / SNS_DST );
    }
  }
  return angle;
}
