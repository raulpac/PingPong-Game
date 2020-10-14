#include "gameLoop.h"
#include <iostream>
#include "SDL.h"

//Game constructor. Initialized player, computer and ball objects.
Game::Game(std::size_t grid_width, 
            std::size_t grid_height, 
            std::size_t ball_width, 
            std::size_t ball_height, 
            std::size_t comp_width, 
            std::size_t comp_height)
    : //player(grid_width, grid_height), 
      //ball(ball_width, ball_height),
      //computer(comp_width, comp_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
        player = std::make_unique<Player>(grid_width, grid_height);
        ball = std::make_unique<Ball>(ball_width, ball_height);
        computer = std::make_unique<Computer>(comp_width, comp_height);
      }

//Run contains the main loop and refreshes the window. It also call update function.
void Game::Run(std::unique_ptr<Input> const &input, Renderer &renderer, std::size_t target_frame_duration) 
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    input->HandleInput(running, *player);
    Update();
    renderer.Render(*player, ball->getPosition(), *computer);

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

//Update function checks for collisions, update object positions and directions. It also increment the scoreboard.
void Game::Update() {

  ball->CollisionPlayer(*player);
  ball->CollisionComputer(*computer);
  // Either there was a collision or not ball needs to be refreshed.
  ball->UpdatePosition();
  //computer direction will try to always follow ball direction
  if (ball->get_y_direction() == Ball::Y_Direction::kDown){
    computer->direction = Computer::Direction::kDown;
  }else{
    computer->direction = Computer::Direction::kUp;
  }
  //Verifies if a player has make a point and increments scoreboard.
  IncreaseScore();
  //Refresh computer's position
  computer->Update();
  //Refresh player's position
  player->Update();
}

//Once a player has made a point computer, player and ball need to be repositioned to original place on window.
//Ball's direction will be calculated randomly with ball's setDirection function.
void Game::ReInit(){
  //generate a random value with y axis value range.
  int y{random_h(engine)};
  //calculate new ball's direction
  ball->setDirection(y);
  //Place ball on the center of x axis and a random place in y axis.
  ball->PlaceBall(ball->get_Grid_Width(), y);
  
  //Erase player's and computer's body to redraw them again on default position.
  while(!player->bodyBar.empty()){
    player->bodyBar.pop_back();
  }
  player->CreateBody();
  while(!computer->bodyBar.empty()){
    computer->bodyBar.pop_back();
  }
  computer->CreateBody();
}

//Check which player has scored a point and calls ReInit() function to redraw positions on default positions.
void Game::IncreaseScore(){
  if(ball->Goal(*player, *computer) == Ball::Player_Goal::kPlayer){
    player_score += 1;
    ReInit();
  }
  if(ball->Goal(*player, *computer) == Ball::Player_Goal::kComputer){
    computer_score += 1;
    ReInit();
  }
}

//When user finishes the game the Winner needs to be declared.
void Game::Winner(){
  if (player_score > computer_score){
    std::cout << "And the wineer is the Player" << std::endl;
  }
  if (computer_score > player_score){
    std::cout << "And the winner is the Computer"  << std::endl;
  }
  if( computer_score == player_score){
    std::cout << "No Winner. Try again" << std::endl; 
  }
}