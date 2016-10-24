//
//  scene.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/24/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <allegro5/allegro.h>
#include <vector>
#include "layer.hpp"

class Scene {
    
public:
    //TODO:
    // Run function having Tick and update for the layers;
    // call layers in order
protected:
    std::vector<Layer> layers;
    
};

#endif /* scene_hpp */
