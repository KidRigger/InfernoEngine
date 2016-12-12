//--------------------------------------------------------------------------------
//
//  texthandler.hpp
//  InfernoEngine
//
//  Created by  Ronak Harkhani on 12/12/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef texthandler_hpp
#define texthandler_hpp

#include "text.hpp"
#include <string>
#include <sstream>
#include <vector>

class TextHandler {
	Vector3 pos_vec;
	int num;
	std::string str;
	std::vector<Text> t;
	int size;

public:
	TextHandler(Vector3 pos_vec, int num);
	TextHandler(Vector3 pos_vec, std::string str);
	void SetString(std::string str);
	void SetNum(int num);
	void Draw();

};


#endif // !texthandler_hpp

//--------------------------------------------------------------------------------
