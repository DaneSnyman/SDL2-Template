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

  //
  // ! Color Wheel.....
  //
  struct ColorWheel
  {
    ColorWheel();
    ColorWheel(double iColorSpeed);
    double green;
    double red;
    double blue;
    double alpha;

    void setColor();

  private:
    double colorSpeed;
    double colorIG;
    double colorIR;
    double colorIB;
    double colorIA;
    Utilities utils;
  };

  ColorWheel::ColorWheel() {}
  ColorWheel::ColorWheel(double iColorSpeed) : colorSpeed(iColorSpeed)
  {
    red = utils.randomNum(iColorSpeed, 255 - iColorSpeed);
    green = utils.randomNum(iColorSpeed, 255 - iColorSpeed);
    blue = utils.randomNum(iColorSpeed, 255 - iColorSpeed);
    alpha = utils.randomNum(iColorSpeed, 255 - iColorSpeed);
    colorIR = iColorSpeed;
    colorIG = iColorSpeed;
    colorIB = iColorSpeed;
    colorIA = iColorSpeed;
  }

  void ColorWheel::setColor()
  {
    colorIG = utils.checkColorI(colorIG, green);
    colorIR = utils.checkColorI(colorIR, red);
    colorIB = utils.checkColorI(colorIB, blue);
    colorIA = utils.checkColorI(colorIA, alpha);
    green += (double)colorIG;
    red += (double)colorIR;
    blue += (double)colorIB;
    alpha += (double)colorIA;
  }
} // namespace dgs

#endif //!__UTILITIES__H__