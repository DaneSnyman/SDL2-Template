#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "Screen.h"
#include "Rectangle.h"
#include "Swarm.h"
#include "SdlGui.h"
#undef main

using namespace std;

int main()
{
  srand((unsigned int)time(NULL)); // Set random seed

  const char *TITLE = "Particle Fun";
  Screen screen(TITLE);

  Rectangle bg(0, 0, screen.WIDTH, screen.HEIGHT, 0.09);
  sdlGui::CreateBlock gui(20, 20, 150, 300, 50, 50, 50, 200);

  Swarm swarm(100, true, 0.5);
  swarm.createSwarm(screen);

  bool isMouseDown = false;
  // * Animation Loop
  bool quit = false;
  while (!quit)
  {
    bg.updateBg(screen);
    screen.clear();
    swarm.update(screen);
    gui.drawBlock(screen);
    screen.update();

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        quit = true;
      }

      if (event.type == SDL_MOUSEBUTTONDOWN)
      {
        isMouseDown = true;
        swarm.hiveMind = true;
        int mX = event.button.x;
        int mY = event.button.y;
        swarm.mX = mX;
        swarm.mY = mY;

        if (gui.checkRegion(mX, mY))
        {
          cout << "Clicked on gui" << endl;
        }
        else
        {
          // swarm.add(screen, mX, mY);
        }
      }

      if (event.type == SDL_MOUSEBUTTONUP)
      {
        isMouseDown = false;
        swarm.hiveMind = false;
      }

      if (event.type == SDL_MOUSEMOTION && isMouseDown)
      {
        int mX = event.button.x;
        int mY = event.button.y;
        swarm.mX = mX;
        swarm.mY = mY;
      }
    }
  }

  // * Exit program
  swarm.close();
  screen.close();
  return 0;
}
