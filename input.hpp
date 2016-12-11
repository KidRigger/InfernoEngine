//
//  input.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef input_hpp
#define input_hpp

#include <allegro5/keyboard.h>

class Input
{
private:
    int x[2];
    ALLEGRO_KEYBOARD_STATE keystate;
public:
    
    Input();
    
    bool Update(void);
    
    //For output of the axes
    int GetAxis(int player);
};

#endif /* input_hpp */
