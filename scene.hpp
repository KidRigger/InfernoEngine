//
//  scene.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <vector>
#include <memory>
#include "object.hpp"

class Scene {
public:
    Scene(float frame_rate);
    void Run(void);
private:
    bool running;
    float frame_rate;
    std::vector< std::unique_ptr<Object> > scene_objects;
};

#endif /* scene_hpp */
