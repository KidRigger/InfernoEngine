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

class Ufo {
	Vector3 pos_vec;
	float radius;

public:
	Ufo(Vector3 pos_vec, float radius = 0);
	void Draw();
	void GetRadius();
};

#endif // !ufo_hpp

