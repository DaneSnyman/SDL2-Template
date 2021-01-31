#ifndef __SDLGUI__H__
#define __SDLGUI__H__
#include <iostream>
#include "Rectangle.h"

using namespace std;
namespace sdlGui
{
  class CreateBlock
  {
    string title;
    Rectangle rect;

  public:
    CreateBlock(int iX, int iY, int iW, int iH, double iR, double iG, double iB, double iA, string iTitle = "");
    void drawBlock(Screen screen);
    bool checkRegion(int x, int y);
  };

  CreateBlock::CreateBlock(int iX, int iY, int iW, int iH, double iR, double iG, double iB, double iA, string iTitle)
  {
    rect = Rectangle(iX, iY, iW, iH, iR, iG, iB, iA);
    title = iTitle;
  }

  void CreateBlock::drawBlock(Screen screen)
  {
    rect.updateGuiBlock(screen);
  }

  bool CreateBlock::checkRegion(int mX, int mY)
  {
    if (mX >= rect.x && mX <= rect.x + rect.width && mY >= rect.y && mY <= rect.y + rect.height)
    {
      return true;
    }
    return false;
  }
} // namespace sdlGui
#endif //!__SDLGUI__H__