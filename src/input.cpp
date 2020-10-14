#include "input.h"
#include <iostream>
#include "SDL.h"
#include "player.h"

// If player hits up or down key and player's direction is not the same. Update the desired direction.

void Input::ChangeDirection(Player &player, Player::Direction button ) const {
  if (player.direction != button) {
    player.direction = button; 
  }
  return;
}

//Detects if a key was pressed and update player's direction by calling ChangeDirection() function.
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