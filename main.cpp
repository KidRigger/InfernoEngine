//
//  main.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/20/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

int main(int argc, char ** argv) {
    
    if(!al_init()){
        return -1;
    }
    ALLEGRO_DISPLAY *dsp = nullptr;
    
    dsp = al_create_display(1440, 900);
    if(dsp == nullptr){
        return -1;
    }
    
    al_clear_to_color(al_map_rgb(255, 0, 0));
    al_flip_display();
    al_rest(1);
    
    al_clear_to_color(al_map_rgb(0, 255, 0));
    al_flip_display();
    al_rest(1);
    
    al_clear_to_color(al_map_rgb(0, 0, 255));
    al_flip_display();
    al_rest(1);
    
    al_destroy_display(dsp);
    
    return 0;
}
