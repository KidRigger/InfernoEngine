//
//  scene.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "scene.hpp"

void Scene::Run(){
    running = true;
    while (running) {
        for(auto it = scene_objects.begin(); it != scene_objects.end(); ++it){
            (*it)->Update();
            (*it)->Draw();
        }
    }
}