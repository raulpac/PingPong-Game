#include <iostream>
#include "input.h"
#include "gameLoop.h"
#include "renderer.h"

int main() {
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

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Input input;
  Game game(kGridWidth, kGridHeight, kBallWidth, kBallHeight, kCompWidth, kCompHeight);
  game.Run(input, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}