//
//  scene.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "scene.hpp"

Scene::Scene(float frame_rate):frame_rate(frame_rate){
    
}

void Scene::Run(){
    while (running) {
        running = input_handler.Update();
        for(auto it = scene_objects.begin(); it != scene_objects.end(); ++it){
            it->Update(1/frame_rate);
            it->Draw();
        }
    }
}