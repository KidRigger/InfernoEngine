//
//  input.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "input.hpp"

Input::Input(void){
    al_install_keyboard();
}

bool Input::Update(void){
    
    al_get_keyboard_state(&keystate);
            
    //Player 1 Arrow Up/Down
    if(al_key_down(&keystate, ALLEGRO_KEY_UP))
    {
        x[0] = -1;
    }
    else if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
    {
        x[0] = +1;
    }
    else
    {
        x[0] = 0;
    }
    
    //Player 2 W/S
    if(al_key_down(&keystate, ALLEGRO_KEY_W))
    {
        x[1] = -1;
    }
    else if(al_key_down(&keystate, ALLEGRO_KEY_S))
    {
        x[1] = 1;
    }
    else
    {
        x[1] = 0;
    }
    
    if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))
    {
        return false;
    }
    
    return false;
}
