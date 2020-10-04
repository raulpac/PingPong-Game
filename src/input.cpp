#include "input.h"
#include <iostream>
#include "SDL.h"

//I need to add my player class
#include "player.h"


// If direction is different change direction

void Input::ChangeDirection(Player &player, Player::Direction button ) const {
  if (player.direction != button) player.direction = button;
  return;
}

void Input::HandleInput(bool &running, Player &player) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(player, Player::Direction::kUp);
          break;

        case SDLK_DOWN:
          ChangeDirection(player, Player::Direction::kDown);
          break;

      }
    }
  }
}