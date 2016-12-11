//
//  input.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef input_hpp
#define input_hpp

#include <allegro5/keyboard.h>
#include "vector3.hpp"

class Input
{
private:
    ALLEGRO_KEYBOARD_STATE keystate;
public:
    
    Input();
    
    bool Update(void);
    
    //For output of the axes
    bool GetKeyDown(char key);
};

#endif /* input_hpp */
