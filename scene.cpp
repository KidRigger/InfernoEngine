//
//  scene.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "scene.hpp"

void Scene::Run(){
    while (running) {
        running = input_handler.Update();
        for(auto it = scene_objects.begin(); it != scene_objects.end(); ++it){
            (*it)->Update();
            (*it)->Draw();
        }
    }
}