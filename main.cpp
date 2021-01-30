#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "Screen.h"

#undef main

using namespace std;

int main()
{
  srand((unsigned int)time(NULL)); // Set random seed
  // * Constants
  const char *TITLE = "Particle Fun";
  static const int swarmSize = 5;
  static const int blockSize = 50;

  Screen screen(TITLE, blockSize);

  // * Animation Loop
  bool quit = false;
  while (!quit)
  {
    screen.update();
    quit = screen.checkPoll();
  }

  // * Exit program
  screen.close();
  return 0;
}
