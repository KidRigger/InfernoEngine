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
#include "object.hpp"

class Shot : public Object {
public:
    Shot (int owner, const Vector3& position, const Vector3& velocity,
          int id, float radius = 1);
    ~Shot(void) { Object::~Object(); }
    void Hit(void);
    void Draw(void);
    void Update(float dt);
    void ChangeID(int id);
    
    Vector3 GetPosition(void) const;
    float GetRadius(void) const;
    bool IsVisible(void) const;
    int GetID(void) const;
    
    int getTypeInt(void) { return 4; }
    int owner(void){return owner_type_int;}
    
private:
    void Destroy(void);
    //bool reg_hit;
    Vector3 pos, vel;
    float rad;
    int id, owner_type_int;
};


#endif /* shots_hpp */
