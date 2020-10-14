#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include "SDL.h"


class Computer {
    public:
        //Computer's body direction values.
        enum class Direction { kUp, kDown };
        //Computer constructor creates computer's body vector.
        Computer(int grid_width, int grid_height)
        : grid_width(grid_width),
          grid_height(grid_height)
        {
          CreateBody();
        }
        //Updates computer's position
        void Update();
        void CreateBody();

        float speed{0.1f};
        float body_head_y;
        float body_tail_y;
        float body_x;
        std::vector<SDL_Point> bodyBar;
        Direction direction = Direction::kDown;

    private:
        
        void UpdatePosition();
        int grid_width;
        int grid_height;
};

#endif