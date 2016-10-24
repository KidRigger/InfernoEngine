//
//  object.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/24/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef object_hpp
#define object_hpp

#include <allegro5/allegro.h>

class Object {
    
public:
    //TODO: Gameobject. Coordintes and manip;
    //ctor with sprite creator
    //dtor destroy sprite
protected:
    float x, y, w, h;
    ALLEGRO_BITMAP *sprite;
};

#endif /* object_hpp */
