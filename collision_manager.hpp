//
//  collision_manager.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/12/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef collision_manager_hpp
#define collision_manager_hpp

#include "vector"
#include "Projectile.hpp"
#include "object.hpp"

namespace Collider {
    bool CollisionCheck(std::vector<Object*> &obj);
};
#endif /* collision_manager_hpp */
