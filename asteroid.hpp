//--------------------------------------------------------------------------------
//
//  asteroid.hpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------


#ifndef asteroid_hpp
#define asteroid_hpp

#include "Projectile.hpp"
#include "vector3.hpp"
#include "renderer.hpp"

class Asteroid : public Projectile{

public:

	Asteroid(const Vector3& pos_vec, float radius = 0);
	void Draw();
	Vector3 GetPosition(void) const ;
	float GetRadius(void) const ;
    void Hit(void);
    void Update(float dt);

private:
    Vector3 pos_vec;
    float radius;
    float angle;
    int shape_id;
    
    Vector3 new_shape[10];
    void Destroy(void);
};

#endif // asteroid_hpp

