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
    mouse_origin.SetValue(x, y, 0);
}

//--------------------------------------------------------------------------------

bool Input::Update(void){
    
    al_get_keyboard_state(&keystate);
    al_get_mouse_state(&mousestate);
    
    if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))
    {
        return false;
    }
    
    return true;
}

//--------------------------------------------------------------------------------

bool Input::GetInput(int input){
    bool res = false;
        if(input & key_w)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_W);
        if(input & key_a)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_A);
        if(input & key_s)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_S);
        if(input & key_d)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_D);
        if(input & key_space)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_SPACE);
        if(input & key_enter)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_ENTER);
        if(input & key_rctrl)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_RCTRL);
        if(input & key_lctrl)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_LCTRL);
        if(input & key_escape)
            res = res || al_key_down(&keystate, ALLEGRO_KEY_ESCAPE);
        if(input & key_lmb)
            res = res || al_mouse_button_down(&mousestate, 1);
        if(input & key_rmb)
            res = res || al_mouse_button_down(&mousestate, 2);
    return res;
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
