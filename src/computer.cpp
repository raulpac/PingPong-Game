#include "computer.h"

void Computer::CreateBody(){
    body_head_y = grid_height / 2;
    body_tail_y = body_head_y + 10;
    body_x = grid_width *7 / 8;
    for (int i=0; i<=body_tail_y-body_head_y; i++){
        SDL_Point extra_cell{ static_cast<int>(body_x), static_cast<int>( body_head_y+i)};
        bodyBar.push_back(extra_cell);
    }
}