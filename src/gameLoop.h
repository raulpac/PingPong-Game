#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <random>
#include "SDL.h"
#include "input.h"
#include "renderer.h"
#include "player.h"
#include "ball.h"
#include "computer.h"

class Game {
 public:
  //Game constructor
  Game(std::size_t grid_width, std::size_t grid_height, 
      std::size_t ball_width, std::size_t ball_height, 
      std::size_t comp_width, std::size_t comp_height);

  void Run(Input const &input, Renderer &renderer, std::size_t target_frame_duration);
  void ReInit();
  void IncreaseScore();
  void Winner();

 private:
  void Update();
  Player player;
  Ball ball;
  Computer computer;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  int player_score{0};
  int computer_score{0};

};

#endif