//
//  main.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/20/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>

int main(int argc, char ** argv) {
    
    
    //Initialization
    if(!al_init()){
        al_show_native_message_box(NULL, "ERROR", "ALLEGRO ERROR", "Allegro could not be initialized", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    ALLEGRO_DISPLAY *dsp = nullptr;
    
    dsp = al_create_display(1440, 900);
    if(dsp == nullptr){
        al_show_native_message_box(NULL, "ERROR", "DISPLAY ERROR", "Display could not be initialized", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    
    
    /* Test part
     
    al_clear_to_color(al_map_rgb(255, 0, 0));
    al_flip_display();
    al_rest(1);
    
    al_clear_to_color(al_map_rgb(0, 255, 0));
    al_flip_display();
    al_rest(1);
    
    al_clear_to_color(al_map_rgb(0, 0, 255));
    al_flip_display();
    al_rest(1);
    */
    
    
    //Game loop goes here
    
    al_destroy_display(dsp);
    
    return 0;
}
