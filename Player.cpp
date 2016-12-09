//
//  Player.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/9/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "Player.hpp"

Player::Player(float x, float y) :
pos(x,y),
rotation(90),
relative_pts{
    Vector3(0,-2*PLAYER_HEIGHT/3),
    Vector3(PLAYER_WIDTH/2,PLAYER_HEIGHT/3),
    Vector3(-PLAYER_WIDTH/2,PLAYER_HEIGHT/3)
}
{}

void LookAt(const Vector3& target) {
    //TODO: Write the Look function
}