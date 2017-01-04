//--------------------------------------------------------------------------------
//
//  ufo.cpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/12/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "ufo.hpp"

const static int thickness = 2;
const static Vector3 shape[8] = {
    Vector3(-0.375,-0.75), Vector3(0.375,-0.75),
    Vector3(0.75,-0.375) , Vector3(1.5,0),
    Vector3(0.875,0.375) , Vector3(-0.875,0.375),
    Vector3(-1.5,0)      , Vector3(-0.75,-0.375)
};


//--------------------------------------------------------------------------------

Ufo::Ufo(const Vector3& pos_vec, const Vector3& velo, float radius):
pos_vec(pos_vec), vel(velo), radius(radius) {
    if (radius == 0) {
        srand((int)time(0));
		this->radius = (rand() % 2 + 1)*20;
	}
}

//--------------------------------------------------------------------------------

Ufo::~Ufo(void){
    Object::~Object();
}

//--------------------------------------------------------------------------------

Vector3 Ufo::GetPosition(void) const {
    return pos_vec;
}

//--------------------------------------------------------------------------------

float Ufo::GetRadius() const {
	return radius;
}

//--------------------------------------------------------------------------------

void Ufo::Draw() {
	for (int i = 0; i != 7; ++i) {
		Renderer::draw_line(pos_vec+radius*shape[i], pos_vec+radius*shape[i + 1],
                            thickness);
	}
    Renderer::draw_line(pos_vec+radius*shape[7], pos_vec+radius*shape[0],
                        thickness);
	Renderer::draw_line(pos_vec+radius*shape[7], pos_vec+radius*shape[2],
                        thickness);
	Renderer::draw_line(pos_vec+radius*shape[6], pos_vec+radius*shape[3],
                        thickness);
}

//--------------------------------------------------------------------------------

void Ufo::Update(float dt){
    pos_vec = pos_vec + vel * dt;
}

//--------------------------------------------------------------------------------

void Ufo::Hit(void) {
    pos_vec = Vector3(-400,-400);
    vel = Vector3();
}

//--------------------------------------------------------------------------------
