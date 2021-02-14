/*
 * Dummy for testing purposes
 */

#ifndef P1M_05_H
#define P1M_05_H

#include <math.h>

int test_p1m_05 = 0;

/*
 * Dummy for testing P1M_T04
 */
float get_rotation(unsigned s3d, unsigned s4d)
{
  if (test_p1m_05 == 0)
  {
    test_p1m_05++;
    return 0.0;
  }
  else if (test_p1m_05 == 1)
  {
    test_p1m_05++;
    return M_PI/8;
  }
  else if (test_p1m_05 == 2)
  {
    test_p1m_05++;
    return M_PI/3;
  }
}

#endif /* P1M_05_H */
