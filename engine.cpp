//
//  engine.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/22/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "engine.hpp"
#include <allegro5/allegro_native_dialog.h>


Engine::Engine(){
    if(!al_init()){
        al_show_native_message_box(NULL, "Allegro Error", "Allegro Error", "Allegro could not be initialized", NULL, 0);
        exit(-1);
    }
}

void Engine::Init(int screen_width,int screen_height){
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    disp = al_create_display(this->screen_width, this->screen_height);
    if(disp==nullptr){
        al_show_native_message_box(NULL, "Display Error", "Display Error", "Allegro could not create display", NULL, 0);
        exit(-1);
    }
}

void Engine::Run(float frame_rate){
    this->frame_rate = frame_rate;
    //TODO: Add current screen variables and tick and update
}

Engine& Engine::GetInstance(void){
    static Engine instance;
    return instance;
}
