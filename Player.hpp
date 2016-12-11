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

#define PLAYER_HEIGHT 10
#define PLAYER_WIDTH 6
#define PLAYER_THICKNESS 1
#include "vector3.hpp"
#include "Projectile.hpp"
#include "object.hpp"
#include <vector>

class Player : public Object {
public:
    Player(float x, float y);
    void LookAt(const Vector3& target);
    void Shoot(void);
    void GetHit(void);
    void Draw(void);
    void Update(void);
private:
    Vector3 pos;
    float rotation;
    Vector3 relative_pts[3];
};

#endif /* Player_hpp */

//--------------------------------------------------------------------------------