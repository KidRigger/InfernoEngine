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

/*
 * Collider namespace containing collision functions...
 * ...usable with the Inferno Objects classes
 * Use Position-Radius method to check for collision
 */

namespace Collider {
    /* Checks for collisions among all the objects in the vector obj */
    bool CollisionCheck(std::vector<Object*> &obj);
    /* Checks if the object obj is on the screen */
    bool OnScreen(Object* obj);     //Pointer Version
    bool OnScreen(Object& obj);     //Reference Version
};
#endif /* collision_manager_hpp */
