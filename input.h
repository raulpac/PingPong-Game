#ifndef INPUT_H
#define INPUT_H

//I need to add my player class here.

//#include "snake.h"


class Input {
 public:
  void HandleInput(bool &running, Snake &snake) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input) const;
};

#endif