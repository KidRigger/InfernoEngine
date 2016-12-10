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

class Projectile {
public:
    virtual void Hit(void) = 0;
    virtual void Draw(void) = 0;
    
    virtual Vector3 GetPosition(void)=0;
    virtual float GetRadius(void)=0;
private:
    virtual void Destroy(void) = 0;
};

#endif /* Projectile_hpp */
