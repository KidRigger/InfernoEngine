//
//  collision_manager.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/12/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "collision_manager.hpp"
#include "vector3.hpp"
#include "Game.hpp"

namespace Collider {
    
    /*
     * Checks for collision between all objects
     * Iterates through the vector and calls CallHit method when collision occurs
     * Uses the position radius method
     * The function essentially assumes all objects are circles.
     */
    bool CollisionCheck(std::vector<Object*> &obj){
        // Outer for loop
        for(auto iter = obj.begin(); iter != obj.end()-1; ++iter) {
            // Data of object_1
            float ro = (*iter)->GetRadius();
            Vector3 pos_o = (*iter)->GetPosition();
            // for loop to check with all the remaining objects
            for(auto it = iter+1; it != obj.end(); ++it){
                
                // Checks if the objects are of the same type...
                // ...collision between 2 objects of same type...
                // ...is ignored
                
                if( (*iter)->getTypeInt() != (*it)->getTypeInt()
                   && (*iter)->getTypeInt()*(*it)->getTypeInt() != 6 ) {
                    
                    if((*iter)->owner() != (*it)->owner()) {
                        float r = ro+(*it)->GetRadius();
                        // Compares square of magnitude instad of magnitude...
                        // ...so that it saves the call to sqrt()
                        if(r*r > (pos_o - (*it)->GetPosition()).SqrMagnitude()){
                            int a = (*iter)->GetID();
                            int b = (*it)->GetID();
                            // Uses TheGame singleton to call hit to object a
                            TheGame::Instance()->CallHit(a);
                            TheGame::Instance()->CallHit(b);
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    
    /*
     * Checks if the object passed into the funstion is on the screen.
     * Returns false only after the object fully exits the screen.
     * 2 Overloads:
     * Pointer overload and Reference overload.
     */
    bool OnScreen(Object* obj) {
        const float r = obj->GetRadius();
        const float x = obj->GetPosition().GetX();
        const float y = obj->GetPosition().GetY();
        auto thisGame = TheGame::Instance();
        return !(x - r > thisGame->GetScreenWidth() ||
                 x + r < 0 ||
                 y - r > thisGame->GetScreenHeight()||
                 y + r < 0);
        
    }
    bool OnScreen(Object& obj) {
        const float r = obj.GetRadius();
        const float x = obj.GetPosition().GetX();
        const float y = obj.GetPosition().GetY();
        auto thisGame = TheGame::Instance();
        return !(x - r > thisGame->GetScreenWidth() ||
                 x + r < 0 ||
                 y - r > thisGame->GetScreenHeight()||
                 y + r < 0);
        
    }
}