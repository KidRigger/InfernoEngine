//
//  Projectile.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef Projectile_hpp
#define Projectile_hpp

#include "vector3.hpp"
#include "player.hpp"
#include "object.hpp"

class Projectile : public Object {
public:
    virtual void Hit(void) = 0;
    virtual void Draw(void) = 0;
    virtual void Update(float dt) = 0;
    
    virtual Vector3 GetPosition(void) const = 0;
    virtual float GetRadius(void) const = 0;
    virtual bool IsVisible(void) const = 0;
    virtual void ChangeID(int id) = 0;
    virtual int GetID(void) = 0;
    ~Projectile(void) {};
};

#endif /* Projectile_hpp */
