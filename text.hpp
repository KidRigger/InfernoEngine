//--------------------------------------------------------------------------------
//
//  text.hpp
//  InfernoEngine
//
//  Created by  Ronak Harkhani on 12/11/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef text_hpp
#define text_hpp

#include "renderer.hpp"

/*
 * Draws a character from the 26 alphabets and the 10 digits on the screen.
 * Uses only allegro primitives and no fonts.
 * Size of characters by default is 20.
 */

class Text {
public:
   	Text(Vector3 pos_vec, char ch, float size = 20);
    void SetChar(char ch);
    void Draw();
private:
    /* Position of the text */
    Vector3 pos_vec;
    /* The character shown on screen */
    char ch;
    float size;
    /* Convenient shorthand for calling Renderer draw_line */
    void l(float i, float j, float p, float q);
};

#endif //text_hpp

//--------------------------------------------------------------------------------
