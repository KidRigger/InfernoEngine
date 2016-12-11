//
//  input.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "input.hpp"
#include <string.h>


Input::Input(void){
    al_install_keyboard();
}

bool Input::Update(void){
    
    al_get_keyboard_state(&keystate);
    
    if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))
    {
        return false;
    }
    
    return true;
}

bool Input::GetKeyDown(char key){
    key = tolower(key);
    switch(key){
        case 'a':
            return al_key_down(&keystate, ALLEGRO_KEY_A);
            break;
        case 's':
            return al_key_down(&keystate, ALLEGRO_KEY_S);
            break;
        case 'w':
            return al_key_down(&keystate, ALLEGRO_KEY_W);
            break;
        case 'd':
            return al_key_down(&keystate, ALLEGRO_KEY_D);
            break;
        case ' ':
            return al_key_down(&keystate, ALLEGRO_KEY_SPACE);
            break;
        default:
            return false;
    };
}

