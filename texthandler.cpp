//--------------------------------------------------------------------------------
//
//  texthandler.cpp
//  InfernoEngine
//
//  Created by  Ronak Harkhani on 12/12/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "texthandler.hpp"

TextHandler::TextHandler(Vector3 pos_vec, int num):pos_vec(pos_vec),num(num) {

	std::stringstream stringy;
	stringy << num;
	str = stringy.str();

	size = str.size();

	for (int i = 0; i != size; ++i ) 
	t.push_back( Text(pos_vec + Vector3(i*30,0), str[i]));
}

void TextHandler::SetNum(int num) {
	size = str.size();

	std::stringstream stringy;
	stringy << num;
	str = stringy.str();
	if (int ds = (str.size()-size) > 0) {
		for (int i = 0; i != ds; ++i) {
			t.push_back(Text(pos_vec + Vector3((size + i) * 30, 0), 0));
		}
	}
	else if (ds < 0) {
		for (int i = 0; i != ds; ++i) {
			t.pop_back();
		}
	}
	auto it2 = t.begin();
	for (auto it1 = str.begin(); it1 != str.end() && it2 != t.end(); ++it1, ++it2) {
		it2->SetChar(*it1);
	}
}



void TextHandler::Draw() {
	for (int i = 0; i < size; ++i)
		t[i].Draw();
}