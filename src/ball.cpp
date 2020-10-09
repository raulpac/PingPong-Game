#include "ball.h"
#include "SDL.h"

void Ball::PlaceBall(){

    //Initial Position for ball is the center.
    position.x = grid_width / 2;
    position.y = grid_height / 2;
}

void Ball::UpdatePosition(){
    //add to speed so it can move
    speed += 0.1;
    
    if(speed >= 1.0){
        //Verified Direction first and then if ball's position is still inside screen size and for collisions.

        //acabas de agregar direcion izquierda, derecha, up and down. Checa como hacer los ifs para el cambio de direccion.
        if(y_direction == Y_Direction::kDown){
            
            if(collision_player1 == true){ 
                //y_direction == Y_Direction::kUp; 
                x_direction = X_Direction::krigth;
            }
            
            if(position.y >= 64){
                y_direction = Y_Direction::kUp;
            }else{
                if(x_direction == X_Direction::krigth){
                    std::cout << "we go down move rigth" << std::endl;
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

void Ball::Collision(Player player){
    
    if(position.y >= player.body_head_y && position.y <= player.body_tail_y && position.x == player.body_x){
        collision_player1=true;
        std::cout << "there was a collision" << std::endl;
    }else{
        collision_player1=false;
    }
}