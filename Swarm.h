#ifndef __SWARM__H__
#define __SWARM__H__
#include "Screen.h"
#include "Rectangle.h"
#include "Utilities.h"

struct Swarm
{
  const int nRects;
  static const int maxAmount = 2000;
  int nextI = 0;

  Swarm(const int iNRects, bool iUniformColor, double iColorSpeed);
  void createSwarm(Screen screen);
  void add(Screen screen, int mX, int mY);
  Rectangle createRandomRect(Screen screen, int setX, int setY);
  void update(Screen screen);
  void close();

  double green;
  double red;
  double blue;
  double alpha;
  bool uniformColor;
  bool hiveMind = false;
  int mX;
  int mY;

private:
  dgs::ColorWheel colorWheel;
  Rectangle *rects;
};

Swarm::Swarm(const int iNRects, bool iUniformColor, double iColorSpeed = 1) : nRects(iNRects), uniformColor(iUniformColor)
{
  colorWheel = dgs::ColorWheel(iColorSpeed);
};

Rectangle Swarm::createRandomRect(Screen screen, int setX = -1, int setY = -1)
{
  int squareSize = utils.randomNum(30, 60);
  int speedX = utils.randPosNeg(utils.randomNum(1, 2));
  int speedY = utils.randPosNeg(utils.randomNum(1, 2));

  int rX = (setX != -1) ? setX : utils.randomNum(squareSize, screen.WIDTH - squareSize * 5);
  int rY = (setY != -1) ? setY : utils.randomNum(squareSize, screen.WIDTH - squareSize * 5);

  return Rectangle(rX,         // x
                   rY,         // y
                   squareSize, // Width
                   squareSize, // Height
                   speedX,     // Horizontal speed
                   speedY,     // Vertical speed
                   1           // ColorSpeed
  );
}

void Swarm::createSwarm(Screen screen)
{
  rects = new Rectangle[maxAmount];
  for (int i = 0; i < nRects; i++)
  {
    rects[i] = createRandomRect(screen);
    nextI++;
  }
}

void Swarm::add(Screen screen, int mX, int mY)
{
  if (nextI < maxAmount)
  {
    rects[nextI] = createRandomRect(screen, mX, mY);
    nextI++;
  }
}

void Swarm::update(Screen screen)
{
  colorWheel.setColor();
  red = colorWheel.red;
  green = colorWheel.green;
  blue = colorWheel.blue;
  alpha = colorWheel.alpha;

  for (int i = 0; i < nextI; i++)
  {
    if (hiveMind)
    {
      rects[i].mX = mX;
      rects[i].mY = mY;
      (uniformColor) ? rects[i].update(screen, true, red, green, blue, alpha) : rects[i].update(screen, true);
    }
    else
    {
      (uniformColor) ? rects[i].update(screen, false, red, green, blue, alpha) : rects[i].update(screen, false);
    }
  }
}

void Swarm::close()
{
  delete[] rects;
}

#endif //!__SWARM__H__