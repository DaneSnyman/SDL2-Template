#include "Screen.h"

Screen::Screen(const char *iTitle) : title(iTitle)
{
  this->checkInit();
  this->createWindow();
  this->createRenderer();
  SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
}

bool Screen::checkInit()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "SDL init failed!\n";
    return false;
  }
  return true;
}

void Screen::createWindow()
{
  this->window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->WIDTH, this->HEIGHT, SDL_WINDOW_SHOWN);

  if (this->window == NULL)
  {
    std::cout << "Error creating window: " << SDL_GetError() << std::endl;
    SDL_Quit();
  }
}

void Screen::createRenderer()
{
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC);

  if (this->renderer == NULL)
  {
    std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_Quit();
  }
}

bool Screen::checkPoll()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      return true;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
      std::cout << "clicked window" << std::endl;
    }
    return false;
  }
  return false;
}

void Screen::drawRect(SDL_Rect rect, int r, int g, int b, int a)
{
  SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
  SDL_RenderFillRect(this->renderer, &rect); // ! Fill
  // SDL_RenderDrawRect(this->renderer, &rect); // ! Outline
}

void Screen::drawGui(SDL_Rect rect, int r, int g, int b, int a)
{
  SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
  SDL_RenderFillRect(this->renderer, &rect); // ! Fill
  SDL_RenderDrawRect(this->renderer, &rect); // ! Outline
}

void Screen::drawBg(int r, int g, int b, int a)
{
  SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void Screen::clear()
{
  SDL_RenderClear(this->renderer);
}

void Screen::update()
{
  SDL_RenderPresent(this->renderer);
}

void Screen::close()
{
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}