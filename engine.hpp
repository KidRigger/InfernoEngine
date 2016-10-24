//
//  engine.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/22/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include <allegro5/allegro.h>
#include "scene.hpp"

class Engine {
    
public:
    void Run(float frame_rate);
    void Init(int screen_width, int screen_height);
    Engine& GetInstance(void);
private:
    //ctors
    Engine();
    Engine(const Engine &);
    Engine& operator=(const Engine &);
    
    float frame_rate;
    int screen_width, screen_height;
    ALLEGRO_DISPLAY *disp = nullptr;
    ALLEGRO_TIMER *timer = nullptr;
    //TODO: Add screen manager
    
};

#endif /* engine_hpp */
