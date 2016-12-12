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

void Text::l(float i, float j, float p, float q) {
	Renderer::draw_line(pos_vec + Vector3(i,j) * size * 0.5,
						pos_vec + Vector3(p,q) * size * 0.5, thick);
}

void Text::Draw() {
    if(ch >= '0' && ch <= '9') {
        for (int i = 0; i < 7; ++i) {
            if (numbers[ch-'0'][i] == true) {
                Renderer::draw_line(pos_vec + line[i][0]*size,
                                    pos_vec + line[i][1]*size, thick);
            }
        }
    }
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		ch = tolower(ch);
		switch (ch) {
		case 'a': 
			l(0,4,  0,2);
			l(0,2,  1,0);
			l(1,0,  2,2);
			l(2,2,  2,4); 
			l(0,2,  2,2);
			break;

		case 'b':
			l(0,4,  0,0);
			l(0,0,  1,0);
			l(1,0,  2,1);
			l(2,1,  1,2);
			l(1,2,  0,2);
			l(1,2,  2,3);
			l(2,3,  1,4);
			l(1,4,  0,4);
			break;

		case 'c':
			l(2,4,  0,4);
			l(0,4,  0,0);
			l(0,0,  2,0);
			break;

		case 'd':
			l(0, 4, 0, 0);
			l(0, 0, 1, 0);
			l(1, 0, 2, 1);
			l(2, 1, 2, 3);
			l(2, 3, 1, 4);
			l(1, 4, 0, 4);
			break;

		case 'e':
			l(2, 4, 0, 4);
			l(0, 4, 0, 0);
			l(0, 0, 2, 0);
			l(0, 2, 2, 2);
			break;

		case 'f':
			l(0, 4, 0, 0);
			l(0, 0, 2, 0);
			l(0, 2, 2, 2);
			break;

		case 'g':
			l(2, 4, 0, 4);
			l(0, 4, 0, 0);
			l(0, 0, 2, 0);
			l(2, 4, 2, 2);
			l(2, 2, 1, 2);
			break;

		case 'h':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 2, 2, 2);
			break;

		case 'i':
			l(0, 0, 2, 0);
			l(1, 0, 1, 4);
			l(2, 4, 0, 4);
			break;

		case 'j':
			l(0, 0, 2, 0);
			l(1, 0, 1, 4);
			l(1, 4, 0, 4);
			l(0, 4, 0, 3);
			break;

		case 'k':
			l(0, 4, 0, 0);
			l(0, 2, 2, 0);
			l(0, 2, 2, 4);
			break;

		case 'l':
			l(0, 4, 0, 0);
			l(2, 4, 0, 4);
			break;

		case 'm':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 0, 1, 2);
			l(1, 2, 2, 0);
			break;

		case 'n':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 0, 2, 4);
			break;

		case 'o':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 0, 2, 0);
			l(2, 4, 0, 4);
			break;

		case 'p':
			l(0, 4, 0, 0);
			l(0, 0, 2, 0);
			l(2, 0, 2, 2);
			l(2, 2, 0, 2);
			break;

		case 'q':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 0, 2, 0);
			l(2, 4, 0, 4);
			l(1, 3, 3, 5);
			break;

		case 'r':
			l(0, 4, 0, 0);
			l(0, 0, 2, 0);
			l(2, 0, 2, 2);
			l(2, 2, 0, 2);
			l(0, 2, 2, 4);
			break;

		case 's':
			l(0, 0, 2, 0);
			l(0, 0, 0, 2);
			l(0, 2, 2, 2);
			l(2, 2, 2, 4);
			l(2, 4, 0, 4);
			break;

		case 't':
			l(0, 0, 2, 0);
			l(1, 0, 1, 4);
			break;

		case 'u':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(2, 4, 0, 4);
			break;

		case 'v':
			l(0, 0, 1, 4);
			l(1, 4, 2, 0);
			break;

		case'w':
			l(0, 4, 0, 0);
			l(2, 4, 2, 0);
			l(0, 4, 1, 2);
			l(1, 2, 2, 4);
			break;

		case 'x':
			l(0, 0, 2, 4);
			l(0, 4, 2, 0);
			break;

		case 'y':
			l(0, 0, 1, 2);
			l(2, 0, 1, 2);
			l(1, 2, 1, 4);
			break;

		case 'z':
			l(0, 0, 2, 0);
			l(2, 0, 0, 4);
			l(2, 4, 0, 4);
			break;

		}	


	}

}

//--------------------------------------------------------------------------------
