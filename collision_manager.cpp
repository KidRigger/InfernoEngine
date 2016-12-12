//
//  collision_manager.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/12/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "collision_manager.hpp"
#include "vector3.hpp"

namespace Collider {
    bool CollisionCheck(Object &object,
                        std::vector<Projectile> &projectiles){
        float ro = object.GetRadius();
        Vector3 pos_o = object.GetPosition();
        for(auto it = projectiles.begin(); it != projectiles.end(); ++it){
            float r = ro+it->GetRadius();
            if(r*r < (pos_o - it->GetPosition()).SqrMagnitude()){
                it->Hit();
                object.Hit();
                return true;
            }
        }
        return false;
    }
}