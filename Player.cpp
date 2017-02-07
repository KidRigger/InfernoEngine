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
#include "input.hpp"
#include "Game.hpp"
#include "score_manager.hpp"

//--------------------------------------------------------------------------------

Player::Player(float x, float y, int id, float speed) :
pos(x,y),
rotation(90),
id(id),
relative_pts{
    Vector3(0,-(float)(2*PLAYER_HEIGHT)/3),
    Vector3(PLAYER_WIDTH/2,(float)PLAYER_HEIGHT/3),
    Vector3(-PLAYER_WIDTH/2,(float)PLAYER_HEIGHT/3)
},
player_speed(speed),
shot_count(0),
player_thrust(250),
flame(false),
invincibility_counter(3)
{
    printf("Player ID: %i\n",id);
}

//--------------------------------------------------------------------------------

void Player::Hit(void){
    if(invincibility_counter <= 0){
        TheScoreManager::Instance()->DecrementLife();
        pos.SetValue(TheGame::Instance()->GetScreenWidth()/2,
                     TheGame::Instance()->GetScreenHeight()/2,
                     0);
        vel.SetValue(0, 0, 0);
        invincibility_counter = 3;
    }
}

void Player::Draw(void){
    Renderer::draw_triangle(pos+relative_pts[0], pos+relative_pts[1],
                            pos+relative_pts[2], PLAYER_THICKNESS);
    //printf("Shoot draw\n");
    if(flame){
        Renderer::draw_triangle(pos-relative_pts[0], pos+relative_pts[1]*0.5, pos+relative_pts[2]*0.5);
    }
}

void Player::Update(float dt){
    shot_count++;
    if(invincibility_counter > 0){
        invincibility_counter-=dt;
    }
    if(TheInput::Instance()->GetInput(key_space | key_rmb)){
        flame = true;
        if(vel.SqrMagnitude() < player_speed*player_speed)
            this->AddForce(player_thrust * relative_pts[0].Normalized());
    }
    else{
        flame=false;
    }
    
    if(TheInput::Instance()->GetInput(key_e)){
        pos = Vector3::RandomInRange(TheGame::Instance()->GetScreenWidth());
    }
    
    vel = vel + acc * dt/2;
    pos = pos + vel * dt;
    vel = vel + acc * dt/2;
    
    if(pos.GetX() > TheGame::Instance()->GetScreenWidth()) {
        pos.SetValue(0, pos.GetY(), pos.GetZ());
    }
    if(pos.GetY() > TheGame::Instance()->GetScreenHeight()) {
        pos.SetValue(pos.GetX(), 0, pos.GetZ());
    }
    if(pos.GetX() < 0) {
        pos.SetValue(TheGame::Instance()->GetScreenWidth(),
                     pos.GetY(), pos.GetZ());
    }
    if (pos.GetY() < 0) {
        pos.SetValue(pos.GetX(), TheGame::Instance()->GetScreenHeight(), 0);
    }
    
    if (vel.SqrMagnitude() > 0){
        vel = vel - player_thrust*vel.Normalized()*dt/3;
    }
    
    this->LookAt(TheInput::Instance()->GetMousePosition());
    if(TheInput::Instance()->GetInput(key_lctrl | key_lmb)){
        this->Shoot();
        //printf("shoot\n");
    }
    acc.SetValue(0, 0, 0);
}

// ---------- Player controlled ---------- //
//--------------------------------------------------------------------------------

void Player::LookAt(const Vector3& target) {
    float rot_by = ((target - pos).Angle()[0] - relative_pts[0].Angle()[0]);
    for(int i = 0; i != 3; ++i){
        relative_pts[i].RotateAroundZ(rot_by);
    }
}

void Player::Shoot(void){
    if(shot_count < 15)
        return;
    TheGame::Instance()->SpawnShot(pos + relative_pts[0]*2, relative_pts[0].Normalized()*300);
    shot_count = 0;
}

void Player::AddForce(const Vector3 &thrust){
    acc = acc + thrust;
}

//--------------------------------------------------------------------------------


