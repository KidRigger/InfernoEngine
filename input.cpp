//--------------------------------------------------------------------------------
//
//  input.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "input.hpp"
#include <allegro5/allegro5.h>

//--------------------------------------------------------------------------------
// Singleton stuff

Input* Input::currentInstance = nullptr;

Input* Input::Instance(){
    if(currentInstance == nullptr)
    {
        currentInstance = new Input();
    }
    return currentInstance;
}

//--------------------------------------------------------------------------------

Input::Input(void){
    al_install_keyboard();
    al_install_mouse();
}

void Input::ResetMouse(ALLEGRO_DISPLAY *disp){
    int x,y;
    al_get_window_position(disp, &x, &y);
    mouse_origin.SetPosition(x, y, 0);
}

//--------------------------------------------------------------------------------

bool Input::Update(void){
    
    al_get_keyboard_state(&keystate);
    
    if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))
    {
        return false;
    }
    
    return true;
}

//--------------------------------------------------------------------------------

bool Input::GetInput(key_code input){
    switch(input){
        case key_w:
            return al_key_down(&keystate, ALLEGRO_KEY_W);
            break;
        case key_a:
            return al_key_down(&keystate, ALLEGRO_KEY_A);
            break;
        case key_s:
            return al_key_down(&keystate, ALLEGRO_KEY_S);
            break;
        case key_d:
            return al_key_down(&keystate, ALLEGRO_KEY_D);
            break;
        case key_space:
            return al_key_down(&keystate, ALLEGRO_KEY_SPACE);
            break;
        case key_enter:
            return al_key_down(&keystate, ALLEGRO_KEY_ENTER);
            break;
        case key_rctrl:
            return al_key_down(&keystate, ALLEGRO_KEY_RCTRL);
            break;
        case key_lctrl:
            return al_key_down(&keystate, ALLEGRO_KEY_LCTRL);
            break;
        case key_escape:
            return al_key_down(&keystate, ALLEGRO_KEY_ESCAPE);
            break;
        default:
            return false;
    }
}

//--------------------------------------------------------------------------------

Vector3 Input::GetMousePosition(void){
    int x,y;
    al_get_mouse_cursor_position(&x, &y);
    return Vector3(x,y)-mouse_origin;
}

//--------------------------------------------------------------------------------

void Input::Clean(){
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

//--------------------------------------------------------------------------------
