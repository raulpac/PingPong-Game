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
          //head_y = head_y-static_cast<float>(bodyBar.size()); 
        }

  void Update();
  void CreateBody();
  bool PlayerCell(int x, int y);
  void ChangeDirection();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float body_head_y;
  float body_tail_y;
  float body_x;
  std::vector<SDL_Point> bodyBar;

 private:
  void UpdatePosition();
  //void UpdateBodyBar(SDL_Point &current_cell, SDL_Point &prev_cell);

  int grid_width;
  int grid_height;
};

#endif