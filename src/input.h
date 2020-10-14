#ifndef INPUT_H
#define INPUT_H
#include "player.h"

//Input classs is the interface between player and keyboard.
class Input {
 public:
  void HandleInput(bool &running, Player &player) const;

 private:
  void ChangeDirection(Player &player, Player::Direction input) const;
};

#endif