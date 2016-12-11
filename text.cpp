//--------------------------------------------------------------------------------
//
//  text.hpp
//  InfernoEngine
//
//  Created by  Ronak Harkhani on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "text.hpp"

Text::Text(Vector3 pos_vec, char ch, float size):
pos_vec(pos_vec), ch(ch), size(size) {}

void Text::SetChar(char ch) {
    this->ch = ch;
}

void Text::Draw() {
    if(ch >= '0' && ch <= '9'){
        for (int i = 0; i < 7; ++i) {
            if (numbers[ch-'0'][i] == true) {
                Renderer::draw_line(pos_vec+line[i][0]*size,
                                    pos_vec+line[i][1]*size, thick);
            }
        }
    }
}

//--------------------------------------------------------------------------------
