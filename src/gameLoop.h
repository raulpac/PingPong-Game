#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <random>
#include "SDL.h"
#include "input.h"
#include "renderer.h"
#include "player.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Input const &input, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Player player;
  //SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  //void PlaceFood();
  void Update();
};

#endif