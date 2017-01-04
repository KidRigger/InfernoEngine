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
#include "object.hpp"

class Ufo : public Object {
public:
	Ufo(const Vector3& pos_vec, const Vector3& velo, float radius = 20);
    ~Ufo(void);
    
    void Draw();
    void Hit();  //Not done
    
    Vector3 GetPosition() const;
	float GetRadius() const;
    void Update(float dt);
    
private:
    Vector3 pos_vec, vel;
    float radius;
};

#endif // !ufo_hpp

