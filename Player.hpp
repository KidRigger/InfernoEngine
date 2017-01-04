//--------------------------------------------------------------------------------
//
//  Player.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/9/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef Player_hpp
#define Player_hpp

#define PLAYER_HEIGHT 20
#define PLAYER_WIDTH 12
#define PLAYER_THICKNESS 1
#include "vector3.hpp"
#include "Projectile.hpp"
#include "object.hpp"
#include <vector>

class Player : public Object {
public:
    Player(float x, float y, float speed = 5);
    ~Player(void) {}
    
    //Object inherited functions
    void Hit(void);
    void Draw(void);
    void Update(float dt);
    
    //Getters
    Vector3 GetPosition(void) const {return pos;}
    float GetRadius(void) const {return float(16.0);}
    
    //Player controlled
    void LookAt(const Vector3& target);
    void Shoot(void);
    void Translate(const Vector3& delta_position);
    void MoveForward(const float& ds);
    
private:
    Vector3 pos;
    float rotation, player_speed;
    Vector3 relative_pts[3];
};

#endif /* Player_hpp */

//--------------------------------------------------------------------------------