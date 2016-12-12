//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/12/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "ufo.hpp"

const static int thickness = 2;

Ufo::Ufo(const Vector3& pos_vec, float radius):
pos_vec(pos_vec), radius(radius) {
	srand((int)time(0));
	if (radius == 0) {
		this->radius = (rand() % 2 + 1)*20;
	}
}

Vector3 Ufo::GetPosition(void) const {
    return pos_vec;
}

float Ufo::GetRadius() const {
	return radius;
}

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

void Ufo::Update(float dt){
    
}