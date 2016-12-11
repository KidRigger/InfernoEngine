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

Text::Text(Vector3 pos_vec, char ch): pos_vec(pos_vec), ch(ch) {
	;
}

void Text::SetChar(char ch) {
	this->ch = ch;
}

void Text::Draw() {
	switch(ch) {
	case '0': for (int i = 0; i < 7; ++i) {
		    if (zero[i] == true) 
				Renderer::draw_line(line[i][1], line[i][2], thick);
	        }
			break;
		case '1':for (int i = 0; i < 7; ++i) {
			if (one[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '2':for (int i = 0; i < 7; ++i) {
			if (two[i] == true) 
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '3':for (int i = 0; i < 7; ++i) {
			if (three[i] == true) 
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '4':for (int i = 0; i < 7; ++i) {
			if (four[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '5':for (int i = 0; i < 7; ++i) {
			if (five[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '6':for (int i = 0; i < 7; ++i) {
			if (six[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '7':for (int i = 0; i < 7; ++i) {
			if (seven[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '8':for (int i = 0; i < 7; ++i) {
			if (eight[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
		case '9':for (int i = 0; i < 7; ++i) {
			if (nine[i] == true)
				Renderer::draw_line(line[i][1], line[i][2], thick);
			}
			break;
	}
}