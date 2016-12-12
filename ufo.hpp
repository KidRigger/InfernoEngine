//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/12/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef ufo_hpp
#define ufo_hpp

#include "renderer.hpp"
#include "vector3.hpp"
#include <stdlib.h>
#include <time.h>

const static Vector3 shape[8] = {
                                    Vector3(-0.375,-0.75), Vector3(0.375,-0.75),
                                    Vector3(0.75,-0.375) , Vector3(1.5,0),
                                    Vector3(0.875,0.375) , Vector3(-0.875,0.375),
                                    Vector3(-1.5,0)      , Vector3(-0.75,-0.375)
                                };

class Ufo {
public:
	Ufo(const Vector3& pos_vec, float radius = 20);
    void Draw();
    Vector3 GetPosition();
	float GetRadius();
private:
    Vector3 pos_vec;
    float radius;
};

#endif // !ufo_hpp

