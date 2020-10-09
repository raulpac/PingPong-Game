#include "gameLoop.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t ball_width, std::size_t ball_height, std::size_t comp_width, std::size_t comp_height)
    : player(grid_width, grid_height), 
      ball(ball_width, ball_height),
      computer(comp_width, comp_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  //PlaceBall(ball_width, ball_height);
  //Ball.PlaceBall(ball_width, ball_height);

}

void Game::Run(Input const &input, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    input.HandleInput(running, player);
    Update();
    renderer.Render(player, ball.position);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

/*
void Game::PlaceBall(std::size_t ball_width, std::size_t ball_height) {
  int x;
  int y;
  //Initial Position for ball is the center.
  ball.x = ball_width/2;
  ball.y = ball_height/2;
  
}
*/

void Game::Update() {
  if (!player.alive) return;
  //Check for collisions
  ball.Collision(player);
  ball.UpdatePosition();
  //ball.x += 1;
  //ball.y += 1;
  
  player.Update();
  
//  int new_x = static_cast<int>(player.head_x);
//  int new_y = static_cast<int>(player.head_y);
  
 /*
  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
  */
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return player.size; }