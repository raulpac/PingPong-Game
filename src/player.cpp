#include "player.h"
#include <cmath>
#include <iostream>


void Player::CreateBody(){
  //Define begin and end of bar position
  body_head_y = grid_height / 2;
  body_tail_y = body_head_y + 10;
  body_x = grid_width / 8;
  //Create the bar points and add them to body vector.
  //As bar only moves up and down. Axis Y is the only who moves.
  //Then head (first element) is in the upper position of Y axis.
  for (int i=0; i<=body_tail_y-body_head_y; i++){
    SDL_Point extra_cell{ static_cast<int>(body_x), static_cast<int>( body_head_y+i)};
    bodyBar.push_back(extra_cell);
  } 
}

//Updates new player's position

void Player::Update() {
  // We first capture the head's cell before updating.
  SDL_Point current_pos_head{ static_cast<int>(body_x), static_cast<int>( body_head_y)};
  SDL_Point current_pos_tail{ static_cast<int>(body_x), static_cast<int>( body_tail_y)};

  UpdatePosition();
  // Capture the head's cell after updating postion.
  SDL_Point new_pos_head{ static_cast<int>(body_x), static_cast<int>(body_head_y)}; 
  SDL_Point new_pos_tail{ static_cast<int>(body_x), static_cast<int>(body_tail_y)}; 
  
  // Update all of the body vector items if the snake has moved and direction is up.
  if( (direction == Player::Direction::kUp) && (current_pos_head.y != new_pos_head.y) ){
    std::reverse(bodyBar.begin(), bodyBar.end());
    bodyBar.push_back(new_pos_head);
    bodyBar.erase(bodyBar.begin());
    std::reverse(bodyBar.begin(), bodyBar.end());
  }
  // Update all of the body vector items if the snake has moved and direction is down.
  if( (direction == Player::Direction::kDown) && (current_pos_tail.y != new_pos_tail.y) ){
    bodyBar.push_back(new_pos_tail);
    bodyBar.erase(bodyBar.begin());
  }
}

void Player::UpdatePosition() {
  //check current direction
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

