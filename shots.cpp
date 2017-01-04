//
//  shots.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "shots.hpp"
#include "renderer.hpp"

//--------------------------------------------------------------------------------

Shot::Shot(const Vector3& position, const Vector3& velocity, float radius):
pos(position), vel(velocity), rad(radius) {}

// ---------- Getters ---------- //
//--------------------------------------------------------------------------------

Vector3 Shot::GetPosition(void) const {
    return pos;
}

float Shot::GetRadius(void) const {
    return rad;
}

bool Shot::IsVisible() const {
    return is_visible;
}

//--------------------------------------------------------------------------------

//TODO:
void Shot::Hit(void) {
    is_visible = false;
    pos = Vector3(-300, -300);
    vel = Vector3();
}

void Shot::Draw(void) {
    if(is_visible)
        Renderer::draw_circle(pos, rad);
}

void Shot::Update(float dt) {
    pos = pos + (vel * dt);
}
