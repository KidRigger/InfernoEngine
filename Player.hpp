//--------------------------------------------------------------------------------
//
//  Player.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/9/16.
//  Completed by Anish Bhobe on 04/25/17
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef Player_hpp
#define Player_hpp

#include "vector3.hpp"
#include "Projectile.hpp"
#include "object.hpp"
#include <vector>

const static float PLAYER_HEIGHT = 20;
const static float PLAYER_WIDTH = 12;
const static float PLAYER_THICKNESS = 1;

class Player : public Object {
public:
    Player(float x, float y, int id = 0, float speed = 150);
    ~Player(void) {}
    
    //Object inherited functions
    void Hit(void);
    void Draw(void);
    void Update(float dt);
    
    //Getters
    Vector3 GetPosition(void) const {return pos;}
    float GetRadius(void) const {return float(16.0);}
    int GetID(void) const {return this->id;}
    
    //Player controlled
    void LookAt(const Vector3& target);
    void Shoot(void);
    void Translate(const Vector3& delta_position);
    
    void AddForce(const Vector3& thrust);
    
    void ChangeID(int id) {this->id = id;}
    
    int getTypeInt(void) { return 1; }
    int owner(void){return 1;}
    
private:
    int id;
    Vector3 pos, vel, acc;
    float rotation, player_speed;
    float invincibility_counter;
    Vector3 relative_pts[3];
    int shot_count;
    float player_thrust;
    bool flame;
};

#endif /* Player_hpp */

//--------------------------------------------------------------------------------