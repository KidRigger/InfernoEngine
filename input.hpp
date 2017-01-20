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
    key_w = 1,
    key_a = 1<<1,
    key_s = 1<<2,
    key_d = 1<<3,
    key_space = 1<<4,
    key_enter = 1<<5,
    key_rctrl = 1<<6,
    key_lctrl = 1<<7,
    key_escape = 1<<8,
    key_lmb = 1<<9,
    key_rmb = 1<<10
};

class Input
{
public:
    
    static Input* Instance(void);
    static void Clean(void);
    bool Update(void);
    
    void ResetMouse(ALLEGRO_DISPLAY *disp);
    
    //For output of the axes
    bool GetInput(int input);
    
    Vector3 GetMousePosition(void);
    
private:
    ALLEGRO_KEYBOARD_STATE keystate;
    ALLEGRO_MOUSE_STATE mousestate;
    
    Vector3 mouse_origin;
    
    static Input* currentInstance;
    
    Input(void);
    ~Input(void) {}
};

typedef Input TheInput;

#endif /* input_hpp */

//--------------------------------------------------------------------------------
