#include <iostream>
#include "input.h"
#include "gameLoop.h"
#include "renderer.h"

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

  // Create renderer object which will handle window settings.
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  // Input object basically is the controller interface for player and keyboard.
  Input input;
  // Game object owns a player, computer and ball objects to run the game logic.
  Game game(kGridWidth, kGridHeight, kBallWidth, kBallHeight, kCompWidth, kCompHeight);
  game.Run(input, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  game.Winner();
  return 0;
}