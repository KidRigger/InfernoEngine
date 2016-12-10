//--------------------------------------------------------------------------------
//
//  Player.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/9/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "Player.hpp"
#include "renderer.hpp"

Player::Player(float x, float y) :
pos(x,y),
rotation(90),
relative_pts{
    Vector3(0,-2*PLAYER_HEIGHT/3),
    Vector3(PLAYER_WIDTH/2,PLAYER_HEIGHT/3),
    Vector3(-PLAYER_WIDTH/2,PLAYER_HEIGHT/3)
}
{}

void Player::LookAt(const Vector3& target) {
    //TODO: Write the Look function
    float rot_by =
    (target - pos).Angle()[0] - relative_pts[0].Angle()[0];
    
    for(int i = 0; i != 3; ++i){
        relative_pts[i].RotateAroundZ(rot_by);
    }
}

void Player::Shoot(void){
    //TODO: Shoot logic
}

void Player::GetHit(void){
    //TODO: Get hit logic
}

void Player::Draw(void){
    Renderer::draw_triangle(pos+relative_pts[0], pos+relative_pts[1],
                            pos+relative_pts[2], 1);
}

//--------------------------------------------------------------------------------