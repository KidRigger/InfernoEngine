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

TextHandler::TextHandler(Vector3 pos_vec, int num, int size):pos_vec(pos_vec),num(num),dim_size(size) {

	std::stringstream stringy;
	stringy << num;
	str = stringy.str();

	size = (int)str.size();

	for (int i = 0; i != size; ++i ) 
	t.push_back( Text(pos_vec + Vector3(i * dim_size * 1.33, 0), str[i]));
}

//--------------------------------------------------------------------------------

TextHandler::TextHandler(Vector3 pos_vec, std::string str, int size) :
	pos_vec(pos_vec), str(str),dim_size(size) {

	size = (int)str.size();
	for (int i = 0; i != size; ++i)
		t.push_back(Text(pos_vec + Vector3(i * dim_size * 1.33, 0),
                         str[i], dim_size)
                    );

}

//--------------------------------------------------------------------------------

void TextHandler::SetNum(int num) {
	size = (int)str.size();

	std::stringstream stringy;
	stringy << num;
	str = stringy.str();
	int ds = (int)str.size() - size;
	if (ds > 0) {
		for (int i = 0; i != ds; ++i) {
			t.push_back(Text(pos_vec + Vector3((size + i) * (dim_size*1.33), 0), 0, dim_size));
		}
	}
	else if (ds <= 0) {
		for (int i = 0; i != -ds; ++i) {
			t.pop_back();
		}
	}
	auto it2 = t.begin();
	for (auto it1 = str.begin(); it1 != str.end() && it2 != t.end(); ++it1, ++it2) {
		it2->SetChar(*it1);
	}
	size = (int)str.size();
}

//--------------------------------------------------------------------------------

void TextHandler::SetString(std::string str) {
	int ds = (int)str.size() - size;
	if (ds > 0) {
		for (int i = 0; i != ds; ++i) {
			t.push_back(Text(pos_vec + Vector3((size + i) * (dim_size*1.33), 0), 0));
		}
	}
	else if (ds <= 0) {
		for (int i = 0; i != -ds; ++i) {
			t.pop_back();
		}
	}
	auto it2 = t.begin();
	for (auto it1 = str.begin(); it1 != str.end() && it2 != t.end(); ++it1, ++it2) {
		it2->SetChar(*it1);
	}
	size = (int)str.size();
}

//--------------------------------------------------------------------------------

void TextHandler::Draw() {
	for (auto it = t.begin(); it != t.end(); ++it)
		it->Draw();
}

//--------------------------------------------------------------------------------
