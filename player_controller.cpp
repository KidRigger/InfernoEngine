//
//  player_controller.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/13/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "player_controller.hpp"

PlayerController::PlayerController(Player* player, Input* input,
                                   float player_speed):player_speed(player_speed) {
    this->player = player;
    input_handler = input;
}

void PlayerController::Act(void){
    if(input_handler->GetInput(key_space)){
        player->MoveForward(player_speed);
    }
}
