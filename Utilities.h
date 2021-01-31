#ifndef __UTILITIES__H__
#define __UTILITIES__H__
#include <iostream>

namespace dgs
{
  struct Utilities
  {
    double randomNum(double min, double max)
    {
      return (((double)rand() / RAND_MAX) * max) + min;
    }

    double randPosNeg(double num)
    {
      double randomNo = (double)rand() / RAND_MAX;
      return (randomNo < 0.5) ? -num : num;
    }

    double checkColorI(double colorI, double color)
    {
      double icol = colorI;
      if ((int)color < 5 || (int)color > 250)
      {
        icol = -icol;
      }
      return icol;
    }
  };

} // namespace dgs

#endif //!__UTILITIES__H__