//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "ufo.hpp"

Ufo::Ufo(Vector3 pos_vec, float radius):pos_vec(pos_vec), radius(radius) {
	;
}

float Ufo::GetRadius() {
	return radius;
}

void Ufo::Draw() {
	for (int i = 0; i < 7; ++i) {
		Renderer::draw_line(radius*shape[i], radius*shape[i + 1], 3);
	}
	Renderer::draw_line(radius*shape[7], radius*shape[2], 3);
	Renderer::draw_line(radius*shape[6], radius*shape[3], 3);

}