#include "gameLoop.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, 
            std::size_t grid_height, 
            std::size_t ball_width, 
            std::size_t ball_height, 
            std::size_t comp_width, 
            std::size_t comp_height)
    : player(grid_width, grid_height), 
      ball(ball_width, ball_height),
      computer(comp_width, comp_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {}

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
    renderer.Render(player, ball.getPosition(), computer);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(player_score, computer_score, frame_count);
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


void Game::Update() {
  //if (!player.alive) return;
  //Check for collisions
  ball.CollisionPlayer(player);
  ball.CollisionComputer(computer);
  ball.UpdatePosition();
  if (ball.get_y_direction() == Ball::Y_Direction::kDown){
    computer.direction = Computer::Direction::kDown;
  }else{
    computer.direction = Computer::Direction::kUp;
  }
  IncreaseScore();
  computer.Update();
  player.Update();
 
}

int Game::GetScore() const { return player_score; }
int Game::GetSize() const { return player.size; }

void Game::ReInit(){
  int y{random_h(engine)};
  ball.PlaceBall(ball.get_Grid_Height()/2, y);
}

// I need to create a function for checking goals and from which player. 
// It also needs to update score and restablished ball position. X on center and a random Y.
void Game::IncreaseScore(){
  if(ball.Goal(player, computer) == Ball::Player_Goal::kPlayer){
    player_score += 1;
    ReInit();
  }
  if(ball.Goal(player, computer) == Ball::Player_Goal::kComputer){
    computer_score += 1;
    ReInit();
  }

}
/*
void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}
*/