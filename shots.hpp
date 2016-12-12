//
//  shots.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef shots_hpp
#define shots_hpp

#include "vector3.hpp"
#include "Projectile.hpp"

class Shot : public Projectile {
public:
    Shot (const Vector3& position, const Vector3& direction,
          float move_speed = 5, float radius = 2);
    void Hit(void);
    void Draw(void);
    void Update(float dt);
    
    Vector3 GetPosition(void) const;
    float GetRadius(void) const;
private:
    virtual void Destroy(void);
    Vector3 pos, dir;
    float speed, rad;
};


#endif /* shots_hpp */
