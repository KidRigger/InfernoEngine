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

/*
 * UFO is the main 'enemy' in asteroids
 * Two types of asteroid, small and large
 * Large has a different shooting method as compared to the small one.
 */

class Ufo : public Object {
public:
	Ufo(const Vector3& pos_vec, const Vector3& velo, float radius = 20);
    ~Ufo(void);
    
    void Draw();
    void Hit();  //Not done
    
    Vector3 GetPosition() const;
    float GetRadius() const;
    int GetID(void) const {return id;}
    void Update(float dt);
    int getTypeInt(void) { return 2; }
    
private:
    Vector3 pos_vec, vel;
    int id;
    float radius;
};

#endif // !ufo_hpp

