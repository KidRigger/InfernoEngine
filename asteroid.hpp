//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------


#ifndef asteroid_hpp
#define asteroid_hpp

#include "Projectile.hpp"
#include "vector3.hpp"
#include "renderer.hpp"

class Asteroid : public Projectile{

	Vector3 pos_vec;
	float radius;
	float angle;
	int shape_id;
	   
	Vector3 shape[3][10] = {Vector3(0.5,1.5), Vector3(1.5,1), Vector3(1,0.5), Vector3(2.5,0), Vector3(1.5,-1), Vector3(0.5,-1.5), Vector3(-1,-1), Vector3(-1,0), Vector3(-1.5,1), Vector3(-0.5,1),
							Vector3(0,2), Vector3(2,1), Vector3(2,-0.5), Vector3(1.5,-1.5), Vector3(0,-2), Vector3(-1.5,-1), Vector3(-1,-1), Vector3(-2,1), Vector3(-0.5,0.5), Vector3(-1,1.5),
							Vector3(-0.5,2), Vector3(0.5,1.5), Vector3(1.5,2), Vector3(1,0.5), Vector3(1.5,-0.5), Vector3(1.5,-1.5), Vector3(0.5,-1), Vector3(0,-2), Vector3(-1.5,0), Vector3(-1.5,1.5) };
	
	Vector3 new_shape[10];

	Asteroid(const Vector3& pos_vec, float radius = 0);
	void Draw();
	Vector3 GetPosition(void);
	float GetRadius(void);


};

#endif // !

