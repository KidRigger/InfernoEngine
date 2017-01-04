//
//  player_controller.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/13/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "player_controller.hpp"

//--------------------------------------------------------------------------------

PlayerController::PlayerController(Player* player,
                                   float player_speed):player_speed(player_speed) {
    this->player = player;
}

//--------------------------------------------------------------------------------

void PlayerController::Act(void){
    if(TheInput::Instance()->GetInput(key_space)){
        player->MoveForward(player_speed);
    }
    player->LookAt(TheInput::Instance()->GetMousePosition());
}

//--------------------------------------------------------------------------------
