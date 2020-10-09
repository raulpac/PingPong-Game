#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "SDL.h"
#include "player.h"
#include "computer.h"

class Ball {
    
    public:
        enum class Y_Direction { kUp, kDown };
        enum class X_Direction {kleft, krigth};

        Ball(int ball_width, int ball_height) 
            : grid_width(ball_width),
              grid_height(ball_height) 
                {
                    PlaceBall();
                }
                
        void PlaceBall();
        void UpdatePosition();
        void CollisionPlayer(Player player);
        void CollisionComputer(Computer computer);
        SDL_Point position{0,0};
        Y_Direction get_y_direction();

    private:
        void UpdateDirection();
        float speed{0.0f};
        int grid_width;
        int grid_height;
        Y_Direction y_direction{Y_Direction::kDown};
        X_Direction x_direction{X_Direction::kleft};
        bool collision_player1{false};
        bool collision_computer{false};
};
#endif