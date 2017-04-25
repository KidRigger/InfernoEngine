//
//  shots.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "Game.hpp"
#include "shots.hpp"
#include "renderer.hpp"
#include "collision_manager.hpp"

//--------------------------------------------------------------------------------

Shot::Shot(int owner, const Vector3& position, const Vector3& velocity, int id, float radius):
pos(position), vel(velocity), id(id), rad(radius), owner_type_int(owner) {}

void Shot::ChangeID(int id){
    this->id = id;
}

// ---------- Getters ---------- //
//--------------------------------------------------------------------------------

Vector3 Shot::GetPosition(void) const {
    return pos;
}

float Shot::GetRadius(void) const {
    return rad;
}

int Shot::GetID(void) const {
    return id;
}

//--------------------------------------------------------------------------------

//TODO:
void Shot::Hit(void) {
    Destroy();
    //printf("shothit\n");
}

void Shot::Draw(void) {
    Renderer::draw_circle(pos, rad);
}

void Shot::Update(float dt) {
    pos = pos + (vel * dt);
    
    if(!Collider::OnScreen(this))
        Destroy();
}

void Shot::Destroy(void) {
    TheGame::Instance()->Destroy(id);
}
