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

class Asteroid : public Object {

public:

	Asteroid(const Vector3& pos_vec, int index,
             const Vector3& velocity = Vector3() ,float radius = 0);
    ~Asteroid(void) { }
    void Draw();
	Vector3 GetPosition(void) const ;
    float GetRadius(void) const ;
    int GetID(void) const {return id;}
    void SetChildLevel(int lvl) {child_level = lvl;}
    
    bool IsVisible(void) const ;
    void Hit(void);
    void Update(float dt);
    void ChangeID(int id);
    
    int getTypeInt(void) { return 3; }
    int owner(void){return 3;}
    
    void Destroy();

private:
    Vector3 pos_vec;
    Vector3 vel;
    float radius;
    float angle;
    int shape_id, id;
    bool is_visible;
    //bool reg_hit;
    static Vector3 shape[3][10];
    int child_level = 0;
};

#endif // asteroid_hpp

