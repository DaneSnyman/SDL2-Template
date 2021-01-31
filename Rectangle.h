#ifndef __RECTANGLE__H__
#define __RECTANGLE__H__
#include "Screen.h"
#include "Utilities.h"

struct Rectangle
{
  int x;
  int y;
  int width;
  int height;

  Rectangle();
  Rectangle(int iX, int iY, int iW, int iH, double iColorSpeed);
  Rectangle(int iX, int iY, int iW, int iH, int iSpeedY, int iSpeedX, double iColorSpeed = 3);
  void draw(Screen screen);
  void update(Screen screen);
  void updateBg(Screen screen);

  double green;
  double red;
  double blue;
  double alpha;

private:
  double colorSpeed;
  double colorIG;
  double colorIR;
  double colorIB;
  double colorIA;
  void setColor();
  dgs::Utilities Utils;

  int speedX;
  int speedY;
};

Rectangle::Rectangle() {}
Rectangle::Rectangle(int iX, int iY, int iW, int iH, int iSpeedY, int iSpeedX, double iColorSpeed)
{
  this->x = iX;
  this->y = iY;
  this->width = iW;
  this->height = iH;
  this->speedX = iSpeedX;
  this->speedY = iSpeedY;
  this->colorSpeed = iColorSpeed;
  this->red = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->green = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->blue = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->alpha = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->colorIR = Utils.randPosNeg(Utils.randomNum(0.5, iColorSpeed));
  this->colorIG = Utils.randPosNeg(Utils.randomNum(0.5, iColorSpeed));
  this->colorIB = Utils.randPosNeg(Utils.randomNum(0.5, iColorSpeed));
  this->colorIA = Utils.randPosNeg(Utils.randomNum(0.5, iColorSpeed));
}
Rectangle::Rectangle(int iX, int iY, int iW, int iH, double iColorSpeed)
{
  this->x = iX;
  this->y = iY;
  this->width = iW;
  this->height = iH;
  this->colorSpeed = iColorSpeed;
  this->red = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->green = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->blue = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->alpha = Utils.randomNum(iColorSpeed, 255 - iColorSpeed);
  this->colorIR = iColorSpeed;
  this->colorIG = iColorSpeed;
  this->colorIB = iColorSpeed;
  this->colorIA = iColorSpeed;
}

void Rectangle::setColor()
{
  this->colorIG = Utils.checkColorI(this->colorIG, this->green);
  this->colorIR = Utils.checkColorI(this->colorIR, this->red);
  this->colorIB = Utils.checkColorI(this->colorIB, this->blue);
  this->colorIA = Utils.checkColorI(this->colorIA, this->alpha);
  this->green += (double)this->colorIG;
  this->red += (double)this->colorIR;
  this->blue += (double)this->colorIB;
  this->alpha += (double)this->colorIA;
}

void Rectangle::draw(Screen screen)
{
  SDL_Rect rect;
  rect.x = this->x;
  rect.y = this->y;
  rect.w = this->width;
  rect.h = this->height;

  screen.drawRect(rect, red, green, blue, alpha);
}

void Rectangle::updateBg(Screen screen)
{
  this->setColor();
  screen.drawBg(red, green, blue, 255);
}

void Rectangle::update(Screen screen)
{
  this->setColor();
  this->draw(screen);

  if (this->x < 5 || this->x > screen.WIDTH - (this->width + 5))
  {
    this->speedX = -this->speedX;
  }

  if (this->y < 5 || this->y > screen.HEIGHT - (this->width + 5))
  {
    this->speedY = -this->speedY;
  }

  this->x += (int)this->speedX;
  this->y += (int)this->speedY;
}

#endif //!__RECTANGLE__H__