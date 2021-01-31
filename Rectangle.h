#ifndef __RECTANGLE__H__
#define __RECTANGLE__H__
#include "Utilities.h"
#include "Screen.h"

dgs::Utilities utils;
struct Rectangle
{
  int x;
  int y;
  int width;
  int height;

  Rectangle();
  Rectangle(int iX, int iY, int iW, int iH, int iR, int iG, int iB, int iA);
  Rectangle(int iX, int iY, int iW, int iH, double iColorSpeed);
  Rectangle(int iX, int iY, int iW, int iH, int iSpeedY, int iSpeedX, double iColorSpeed = 3);
  void draw(Screen screen);
  void update(Screen screen, bool hiveMind, int iR, int iG, int iB, int iA);
  void updateBg(Screen screen);
  void updateGuiBlock(Screen screen);

  double green;
  double red;
  double blue;
  double alpha;

  int mX;
  int mY;

private:
  double colorSpeed;
  dgs::ColorWheel colorWheel;
  void setColor();

  int speedX;
  int speedY;
};

Rectangle::Rectangle() {}
Rectangle::Rectangle(int iX, int iY, int iW, int iH, int iR, int iG, int iB, int iA)
{
  x = iX;
  y = iY;
  width = iW;
  height = iH;
  red = iR;
  green = iG;
  blue = iB;
  alpha = iA;
};
Rectangle::Rectangle(int iX, int iY, int iW, int iH, double iColorSpeed)
{
  x = iX;
  y = iY;
  width = iW;
  height = iH;
  colorSpeed = iColorSpeed;
  colorWheel = dgs::ColorWheel(iColorSpeed);
}
Rectangle::Rectangle(int iX, int iY, int iW, int iH, int iSpeedY, int iSpeedX, double iColorSpeed)
{
  x = iX;
  y = iY;
  width = iW;
  height = iH;
  speedX = iSpeedX;
  speedY = iSpeedY;
  colorSpeed = iColorSpeed;
  colorWheel = dgs::ColorWheel(iColorSpeed);
}

void Rectangle::setColor()
{
  colorWheel.setColor();
  red = colorWheel.red;
  green = colorWheel.green;
  blue = colorWheel.blue;
  alpha = colorWheel.alpha;
}

void Rectangle::draw(Screen screen)
{
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  screen.drawRect(rect, red, green, blue, alpha);
}

void Rectangle::updateBg(Screen screen)
{
  setColor();
  screen.drawBg(red, green, blue, 255);
}

void Rectangle::updateGuiBlock(Screen screen)
{
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  screen.drawGui(rect, red, green, blue, alpha);
}

void Rectangle::update(Screen screen, bool hiveMind, int iR = -1, int iG = -1, int iB = -1, int iA = -1)
{
  if (iR != -1 && iG != -1 && iB != -1)
  {
    red = iR;
    green = iG;
    blue = iB;
    alpha = iA;
  }
  else
  {
    setColor();
  }

  draw(screen);
  if (hiveMind)
  {

    if ((x < mX - width / 2 && speedX < 0) || (x > mX - width / 2 && speedX > 0))
    {
      speedX = -speedX;
    }

    if ((y < mY - height / 2 && speedY < 0) || (y > mY - height / 2 && speedY > 0))
    {
      speedY = -speedY;
    }
  }
  else
  {
    if (x < 5 || x > screen.WIDTH - (width + 5))
    {
      speedX = -speedX;
    }

    if (y < 5 || y > screen.HEIGHT - (width + 5))
    {
      speedY = -speedY;
    }
  }

  if (!hiveMind || (hiveMind && y != mY))
  {
    x += (int)speedX;
  }

  if (!hiveMind || (hiveMind && x != mX))
  {
    y += (int)speedY;
  }
}

#endif //!__RECTANGLE__H__