#include "p1m_04.hpp"
#include "p1m_01.hpp"
#include "p1m_06.hpp"

/*
 * Checks if rotation movement is needed.
 * Checks if there is a gap at the left.
 * If true, advances to new corridor.
 * Else, checks if there is an obstacle in front.
 * If true, turns left and keeps advancing.
 */
void rotation_movement()
{
  unsigned gaps;
  /* Scan the distance of all sensors */
  unsigned s1d, s2d, s3d, s4d;
  s1d = distance_sensor(1);
  delay(5);
  s2d = distance_sensor(2);
  delay(5);
  s3d = distance_sensor(3);
  delay(5);
  s4d = distance_sensor(4);
  /* Calculate side_distance */
  unsigned side_distance = (s3d + s4d)/2;
  /* Calculate front_distance */
  unsigned front_distance = (s1d + s2d)/2;
  /* If front distance is less than 100mm and
   * side distance is less than the defined. */
   if (front_distance < 100 and
       side_distance < SIDE_DISTANCE)
   {
     /* Perform a 90º turn left */
     call_PID(0.0, 0.0, 0, 0);
     gaps = (M_PI/2)*GAPS_PER_RAD;
     call_PID(-MAX_SPEED, MAX_SPEED, gaps, gaps);
   }
   /* If side distance is more than the defined. */
   else if (side_distance > SIDE_DISTANCE)
   {
     /* Advance 130 mm and stop */
     gaps = 130 * MM_PER_GAP;
     call_PID(MAX_SPEED, MAX_SPEED, gaps, gaps);
     /* Perform a 90º turn right */
     gaps = (M_PI/2)*GAPS_PER_RAD;
     call_PID(MAX_SPEED, -MAX_SPEED, gaps, gaps);
     /* Advance the side distance minus 200mm and stop */
     gaps = (side_distance - 200) * MM_PER_GAP;
     call_PID(MAX_SPEED, MAX_SPEED, gaps, gaps);  
   }
}
