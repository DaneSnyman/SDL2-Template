#ifndef __SCREEN__H__
#define __SCREEN__H__
#include <iostream>
#include "SDL.h"

struct Screen
{
  static const int WIDTH = 1024;
  static const int HEIGHT = 768;
  Screen(const char *iTitle);
  bool checkPoll();
  void close();
  void update();
  void clear();
  void drawRect(SDL_Rect rect, int r, int g, int b, int a);
  void drawGui(SDL_Rect rect, int r, int g, int b, int a);
  void drawBg(int r, int g, int b, int a);

private:
  const char *title;
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool checkInit();
  void createWindow();
  void createRenderer();
};

#endif //!__SCREEN__H__