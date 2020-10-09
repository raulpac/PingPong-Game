#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "SDL.h"

class Player {
 public:
  enum class Direction { kUp, kDown };

  Player(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
        {
          CreateBody(); 
        }

  void Update();
  //void ChangeDirection();

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float body_head_y;
  float body_tail_y;
  float body_x;
  std::vector<SDL_Point> bodyBar;
  Direction direction = Direction::kUp;
 private:
  void CreateBody();
  void UpdatePosition();
  
  
  int grid_width;
  int grid_height;
};

#endif