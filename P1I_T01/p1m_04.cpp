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
void rotation_movement(unsigned s1d,unsigned s2d,unsigned s3d,unsigned s4d)
{
  unsigned gaps;
  /* Calculate side_distance */
  long unsigned side_distance = (s3d + s4d)/2;
  /* Calculate front_distance */
  long unsigned front_distance = min(s1d, s2d);
  /* If side distances are more than the defined. */
  if (s4d > SIDE_DISTANCE)
   {
     /* Advance 65 mm and stop */
     gaps = 65 * MM_PER_GAP;
     call_PID(MAX_SPEED, MAX_SPEED, gaps, gaps);
     /* Perform a 90º turn right */
     gaps = (M_PI/2)*GAPS_PER_RAD;
     call_PID(MAX_SPEED, -MAX_SPEED, gaps, gaps);
     /* Advance 300mm and stop */
     gaps = (300) * MM_PER_GAP;
     call_PID(MAX_SPEED, MAX_SPEED, gaps, gaps);  
   }
  /* If front distance is less than 150mm and
   * side distance is less than the defined. */
   else if (front_distance < 150 and
       side_distance < SIDE_DISTANCE)
   {
     /* Perform a 90º turn left */
     call_PID(0.0, 0.0, 0, 0);
     gaps = (M_PI/2)*GAPS_PER_RAD;
     call_PID(-MAX_SPEED, MAX_SPEED, gaps, gaps);
   }
   else
   {
    /* MISRA C++ 2008 */
   }
}
