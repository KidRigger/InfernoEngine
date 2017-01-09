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
    bool CollisionCheck(std::vector<Object*> &obj){
        for(auto iter = obj.begin(); iter != obj.end()-1; ++iter) {
            float ro = (*iter)->GetRadius();
            Vector3 pos_o = (*iter)->GetPosition();
            for(auto it = iter+1; it != obj.end(); ++it){
                if( (*iter)->getTypeInt() != (*it)->getTypeInt()) {
                    float r = ro+(*it)->GetRadius();
                    if(r*r > (pos_o - (*it)->GetPosition()).SqrMagnitude()){
                        int a = (*iter)->GetID();
                        int b = (*it)->GetID();
                        TheGame::Instance()->CallHit(a);
                        TheGame::Instance()->CallHit(b);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
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