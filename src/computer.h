#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include "SDL.h"


class Computer {
    public:
        enum class Direction { kUp, kDown };
        Computer(int grid_width, int grid_height)
        : grid_width(grid_width),
          grid_height(grid_height)
        {
          CreateBody();
          //head_y = head_y-static_cast<float>(bodyBar.size()); 
        }

        void Update();
        

        float speed{0.1f};
        int size{1};
        bool alive{true};
        float body_head_y;
        float body_tail_y;
        float body_x;
        std::vector<SDL_Point> bodyBar;
        Direction direction = Direction::kDown;

    private:
        void CreateBody();
        void UpdatePosition();
        int grid_width;
        int grid_height;
};

#endif