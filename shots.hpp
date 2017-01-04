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
    Shot (const Vector3& position, const Vector3& velocity, float radius = 2);
    ~Shot(void) { Object::~Object(); }
    void Hit(void);
    void Draw(void);
    void Update(float dt);
    
    Vector3 GetPosition(void) const;
    float GetRadius(void) const;
    bool IsVisible(void) const;
private:
    Vector3 pos, vel;
    float rad;
    bool is_visible;
};


#endif /* shots_hpp */
