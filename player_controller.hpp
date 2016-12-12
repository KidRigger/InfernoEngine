//
//  player_controller.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/13/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef player_controller_hpp
#define player_controller_hpp

#include "Player.hpp"
#include "input.hpp"

class PlayerController {
public:
    PlayerController(Player* player, Input* input, float player_speed = 5);
    void Act(void);
private:
    float player_speed;
    Player *player;
    Input *input_handler;
};

#endif /* player_controller_hpp */
