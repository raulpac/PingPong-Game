#include <iostream>
#include "input.h"
#include "gameLoop.h"
#include "renderer.h"
#include <memory>

int main() {

  // Define initial setting for window size.
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{800};
  constexpr std::size_t kScreenHeight{650};
  constexpr std::size_t kGridWidth{64};
  constexpr std::size_t kGridHeight{64};
  constexpr std::size_t kBallWidth{64};
  constexpr std::size_t kBallHeight{64};
  constexpr std::size_t kCompWidth{64};
  constexpr std::size_t kCompHeight{64};

  // Create renderer pointer object which will handle window settings.
  //Renderer *renderer = new Renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  
  // Input object basically is the controller interface for player and keyboard.
  std::unique_ptr<Input> input = std::make_unique<Input>();
  // Game object owns a player, computer and ball objects to run the game logic.
  std::unique_ptr<Game> game = std::make_unique<Game>(kGridWidth, kGridHeight, kBallWidth, kBallHeight, kCompWidth, kCompHeight);
  game->Run(std::move(input), std::move(renderer), kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  game->Winner();
  return 0;
}