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
    key_lctrl,
    key_escape
};

class Input
{
public:
    
    static Input* Instance(void);
    static void Clean(void);
    bool Update(void);
    
    void ResetMouse(ALLEGRO_DISPLAY *disp);
    
    //For output of the axes
    bool GetInput(key_code input);
    
    Vector3 GetMousePosition(void);
    
private:
    ALLEGRO_KEYBOARD_STATE keystate;
    
    Vector3 mouse_origin;
    
    static Input* currentInstance;
    
    Input(void);
    ~Input(void) {}
};

typedef Input TheInput;

#endif /* input_hpp */

//--------------------------------------------------------------------------------
