//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef ufo_hpp
#define ufo_hpp

#include "renderer.hpp"

Vector3 shape[8] = { Vector3(-0.375, 0.75), Vector3(0.375, 0.75), Vector3(0.75, 0.375),
					 Vector3(1.5, 0), Vector3(0.875, -0.375), Vector3(-0.875, -0.375),
					 Vector3(-1.5, 0), Vector3(-0.75, 0.375) };

class Ufo {
	Vector3 pos_vec;
	float radius;

public:
	Ufo(Vector3 pos_vec, float radius = 0);
	void Draw();
	float GetRadius();
};

#endif // !ufo_hpp

