#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Player {
 public:
  //Player's body direction values
  enum class Direction { kUp, kDown };
  //Player constructor
  Player(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
        {
          CreateBody(); 
        }
  //calculates new player's position
  void Update();
  //Creates player's body
  void CreateBody();

  float speed{0.1f};
  float body_head_y;
  float body_tail_y;
  float body_x;
  std::vector<SDL_Point> bodyBar;
  Direction direction = Direction::kUp;
 private:
  
  void UpdatePosition();
  int grid_width;
  int grid_height;
};

#endif