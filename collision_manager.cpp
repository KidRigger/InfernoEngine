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
    bool CollisionCheck(std::vector<Object*> &obj){
        for(auto iter = obj.begin(); iter != obj.end()-1; ++iter) {
            float ro = (*iter)->GetRadius();
            Vector3 pos_o = (*iter)->GetPosition();
            for(auto it = iter+1; it != obj.end(); ++it){
                float r = ro+(*it)->GetRadius();
                if(r*r < (pos_o - (*it)->GetPosition()).SqrMagnitude()){
                    (*it)->Hit();
                    (*iter)->Hit();
                    return true;
                }
            }
        }
        return false;
    }
}