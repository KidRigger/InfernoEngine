//--------------------------------------------------------------------------------
//
//  input.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef input_hpp
#define input_hpp

#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>
#include "vector3.hpp"

enum key_code {
    key_w = 0,
    key_a,
    key_s,
    key_d,
    key_space,
    key_enter,
    key_rctrl,
    key_lctrl
};

class Input
{
private:
    int x[2];
    ALLEGRO_KEYBOARD_STATE keystate;
public:
    
    Input(void);
    ~Input(void);
    
    bool Update(void);
    
    //For output of the axes
    bool GetInput(key_code input);
    
    Vector3 GetMousePosition(void);
    
};

#endif /* input_hpp */

//--------------------------------------------------------------------------------
