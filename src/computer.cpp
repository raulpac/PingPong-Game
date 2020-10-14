#include "computer.h"

//Creates and fills computer's body
void Computer::CreateBody(){
    body_head_y = grid_height / 2;
    body_tail_y = body_head_y + 10;
    body_x = grid_width *7 / 8;
    for (int i=0; i<=body_tail_y-body_head_y; i++){
        SDL_Point extra_cell{ static_cast<int>(body_x), static_cast<int>( body_head_y+i)};
        bodyBar.push_back(extra_cell);
    }
}

//Updates new computer's position
void Computer::Update(){
    // Capture the head's cell before updating postion.
    SDL_Point current_pos_head{ static_cast<int>(body_x), static_cast<int>( body_head_y)};
    SDL_Point current_pos_tail{ static_cast<int>(body_x), static_cast<int>( body_tail_y)};
    UpdatePosition();
    // Capture the head's cell after updating postion.
    SDL_Point new_pos_head{ static_cast<int>(body_x), static_cast<int>(body_head_y)}; 
    SDL_Point new_pos_tail{ static_cast<int>(body_x), static_cast<int>(body_tail_y)}; 

    //If computer's body has moved and direction is up update body.
    if( (direction == Computer::Direction::kUp) && (current_pos_head.y != new_pos_head.y) ){
        std::reverse(bodyBar.begin(), bodyBar.end());
        bodyBar.push_back(new_pos_head);
        bodyBar.erase(bodyBar.begin());
        std::reverse(bodyBar.begin(), bodyBar.end());
    }
    //If computer's body has moved and direction is up update body
    if( (direction == Computer::Direction::kDown) && (current_pos_tail.y != new_pos_tail.y) ){
        bodyBar.push_back(new_pos_tail);
        bodyBar.erase(bodyBar.begin());
    }


}

void Computer::UpdatePosition(){
    switch (direction) {
        //update up postion
        case Direction::kUp:
        if (body_head_y>=0){
            body_head_y -= speed;
            body_tail_y -= speed;
            break;
        }
        //update down position
        case Direction::kDown:
        if (body_tail_y<=grid_height){
            body_head_y += speed;
            body_tail_y += speed;
            break;
        }
    }
}

