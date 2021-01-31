#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "Screen.h"
#include "Rectangle.h"

#undef main

using namespace std;

int main()
{
  srand((unsigned int)time(NULL)); // Set random seed
  // * Constants
  const char *TITLE = "Particle Fun";
  Screen screen(TITLE);

  dgs::Utilities utils;

  Rectangle bg(0, 0, screen.WIDTH, screen.HEIGHT, 0.09);

  const int nRects = 20;
  Rectangle *rects = new Rectangle[nRects];
  for (int i = 0; i < nRects; i++) // TODO: Create swarm
  {
    int squareSize = utils.randomNum(30, 60);
    int speedX = utils.randPosNeg(utils.randomNum(1, 2));
    int speedY = utils.randPosNeg(utils.randomNum(1, 2));

    rects[i] = Rectangle(utils.randomNum(squareSize, screen.WIDTH - squareSize * 5),  // x
                         utils.randomNum(squareSize, screen.HEIGHT - squareSize * 5), // y
                         squareSize,                                                  // Width
                         squareSize,                                                  // Height
                         speedX,                                                      // Horizontal speed
                         speedY,                                                      // Vertical speed
                         1                                                            // ColorSpeed
    );
  }

  // * Animation Loop
  bool quit = false;
  while (!quit)
  {
    bg.updateBg(screen);
    screen.clear();
    for (int i = 0; i < nRects; i++) // TODO: Create swarm
    {
      rects[i].update(screen);
    }
    screen.update();
    quit = screen.checkPoll();
  }

  // * Exit program
  delete[] rects;
  screen.close();
  return 0;
}
