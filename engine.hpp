//
//  engine.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

class Engine {
public:
    Engine(int screen_width, int screen_height, float FPS);
    void Run(void);
private:
    int screen_width, screen_height;
    float frame_rate;
};

#endif /* engine_hpp */
