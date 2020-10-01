#include "input.h"
#include <iostream>
#include "SDL.h"

//I need to add my player class
//#include "snake.h"


// If direction is different change direction

void Input::ChangeDirection(Snake &snake, Snake::Direction button ) const {
  if (snake.direction != button) snake.direction = button;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake::Direction::kDown);
          break;

      }
    }
  }
}