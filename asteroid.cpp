//--------------------------------------------------------------------------------
//
//  asteroid.cpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "asteroid.hpp"

#include <time.h> 

const static Vector3 shape[3][10] = {
	{Vector3(0.5,1.5), Vector3(1.5,1), Vector3(1,0.5), Vector3(2.5,0),
		Vector3(1.5,-1), Vector3(0.5,-1.5), Vector3(-1,-1), Vector3(-1,0),
		Vector3(-1.5,1), Vector3(-0.5,1)},
	{Vector3(0,2), Vector3(2,1), Vector3(2,-0.5), Vector3(1.5,-1.5),
		Vector3(0,-2), Vector3(-1.5,-1), Vector3(-1,-1), Vector3(-2,1),
		Vector3(-0.5,0.5), Vector3(-1,1.5) },
	{Vector3(-0.5,2), Vector3(0.5,1.5), Vector3(1.5,2), Vector3(1,0.5),
		Vector3(1.5,-0.5), Vector3(1.5,-1.5), Vector3(0.5,-1), Vector3(0,-2),
		Vector3(-1.5,0), Vector3(-1.5,1.5)} };


Asteroid::Asteroid(const Vector3& pos_vec, float radius): pos_vec(pos_vec), radius(radius) {
	srand((int)time(0));

	if(this->radius == 0)
	this->radius = rand() % 60 + 20.0;

	angle = rand() % 360 + 0.0;

	shape_id = rand() % 3;
	

	for (int i = 0; i <= 9; i++) {
		new_shape[i] = shape[shape_id][i] * radius;
		new_shape[i].RotateAroundZ(angle);
	}
}

void Asteroid::Draw() {

	for (int i = 0; i < 9; i++) {
		Renderer::draw_line(pos_vec + new_shape[i], pos_vec + new_shape[i + 1], 3);
	}
	Renderer::draw_line(pos_vec + new_shape[0], pos_vec + new_shape[9], 3);
}

Vector3 Asteroid::GetPosition() {
	return pos_vec;
}

float Asteroid::GetRadius() {
	return 2*radius;
}