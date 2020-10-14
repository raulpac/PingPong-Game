#include "ball.h"
#include "SDL.h"

void Ball::PlaceBall(int grid_width, int grid_heigth){
    //Initial Position for ball is the center.
    position.x = grid_width / 2;
    position.y = grid_height / 2;
}

void Ball::UpdatePosition(){
    //add to speed so it can move
    speed += 0.1;
    
    if(speed >= 1.0){
    //Verify Direction, collisions and if ball is still inside window's size. 
    //Then, updates x and y directions and collision values.
        if(y_direction == Y_Direction::kDown){ 
            if(collision_player1 == true){ 
                x_direction = X_Direction::krigth;
            }
            if(collision_computer == true){ 
                x_direction = X_Direction::kleft;
            }
            //If ball is on botton of the window change direction to up.
            if(position.y >= 64){
                y_direction = Y_Direction::kUp;
            }else{
                if(x_direction == X_Direction::krigth){
                    position.x += 1;
                    position.y += 2;
                }else{
                    position.x -= 1;
                    position.y += 2;
                }
            }
        }
            
        if(y_direction == Y_Direction::kUp){

            if(collision_player1 == true){    
                x_direction = X_Direction::krigth;
            }
            if(collision_computer == true){ 
                x_direction = X_Direction::kleft;
            }
            //If ball is on top of the window change direction to down.
            if(position.y <= 0){
                y_direction = Y_Direction::kDown;
            }else{
                if(x_direction == X_Direction::krigth){
                    std::cout << "we go up and right" << std::endl;
                    position.x += 1;
                    position.y -= 2;
                }else{
                    position.x -= 1;
                    position.y -= 2;
                }
                
            }
        }
        speed = 0.0;
    }
}

void Ball::CollisionPlayer(Player player){
    
    if(position.y >= player.body_head_y && position.y <= player.body_tail_y && position.x == player.body_x){
        collision_player1=true;
        std::cout << "there was a collision with player" << std::endl;
    }else{
        collision_player1=false;
    }
}

void Ball::CollisionComputer(Computer computer){
    
    if(position.y >= computer.body_head_y && position.y <= computer.body_tail_y && position.x == computer.body_x){
        collision_computer=true;
        std::cout << "there was a collision with computer" << std::endl;
    }else{
        collision_computer=false;
    }
}

//Tells who has score a goal

Ball::Player_Goal Ball::Goal(Player player, Computer computer){
    if(position.x >= computer.body_x +4){
        std::cout << "Player's goal" << std::endl;
        return Ball::Player_Goal::kPlayer;
    }
    if(position.x <= player.body_x - 4){
        std::cout << "Computer's goal" << std::endl;
        return Ball::Player_Goal::kComputer;
    }
    return Ball::Player_Goal::kNoGoal;
}

Ball::Y_Direction Ball::get_y_direction(){
    return y_direction;
} 

void Ball::setDirection(int y){
    if(y>=0 && y <= grid_height/4){
        y_direction = Y_Direction::kDown;
        x_direction = X_Direction::kleft;
    }
    if(y > grid_height/4 && y <= grid_height*2/4){
        y_direction = Y_Direction::kDown;
        x_direction = X_Direction::krigth;
    }
    if(y > grid_height*2/4 && y <= grid_height*3/4){
        y_direction = Y_Direction::kUp;
        x_direction = X_Direction::kleft;
    }
    if(y > grid_height*3/4 && y <= grid_height){
        y_direction = Y_Direction::kUp;
        x_direction = X_Direction::krigth;
    }

}

int Ball::get_Grid_Width(){
    return grid_width;
}

int Ball::get_GridHeight(){
    return grid_height;
}

SDL_Point Ball::getPosition(){
    return position;
}