#ifndef INPUT_H
#define INPUT_H
#include "player.h"


class Input {
 public:
  void HandleInput(bool &running, Player &player) const;

 private:
  void ChangeDirection(Player &player, Player::Direction input) const;
};

#endif