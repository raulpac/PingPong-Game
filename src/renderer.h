#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "player.h"
#include "computer.h"

class Renderer {
 public:
  //Renderer Constructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

 //Draws all objects in window
  void Render(Player const player, SDL_Point const &ball, Computer const computer);
  //Draws players' scores in title.
  void UpdateWindowTitle(const int player_score, const int computer_score, const int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif