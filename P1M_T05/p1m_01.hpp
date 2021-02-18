/*
 * Dummy for testing purposes
 */

#ifndef P1M_01_H
#define P1M_01_H

int test_p1m_01 = 0;

/*
 * Dummy for testing P1M_T05
 */
unsigned distance_sensor(int sensor)
{
  if (test_p1m_01 == 0)
  {
    switch(sensor)
    {
      case 1:
        return 150;
      case 2:
        return 150;
      case 3:
        return 150;
      case 4:
        test_p1m_01++;
        return 150;
    }
  }
  else if (test_p1m_01 == 1)
  {
    switch(sensor)
    {
      case 1:
        return 90;
      case 2:
        return 90;
      case 3:
        return 150;
      case 4:
        test_p1m_01++;
        return 150;
    }
  }
  else if (test_p1m_01 == 2)
  {
    switch(sensor)
    {
      case 1:
        return 150;
      case 2:
        return 150;
      case 3:
        return 300;
      case 4:
        test_p1m_01++;
        return 300;
    }
  }
}

#endif /* P1M_01_H */
