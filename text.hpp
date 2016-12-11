//--------------------------------------------------------------------------------
//
//  text.hpp
//  InfernoEngine
//
//  Created by  Ronak Harkhani on 12/11/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#ifndef text_hpp
#define text_hpp

#include "renderer.hpp"

const static Vector3 line[7][2] = { { Vector3(1,1),Vector3(1,0) },
									{ Vector3(1,0),Vector3(0,0) },
									{ Vector3(0,0),Vector3(0,1) },
									{ Vector3(0,1),Vector3(0,2) },
									{ Vector3(0,2),Vector3(1,2) },
									{ Vector3(1,2),Vector3(1,1) },
									{ Vector3(1,1),Vector3(0,1) } };

//line 0 -> top right ,  go counterclockwise for others
//line 6 horizontal

const static bool zero[7] = { true, true, true, true, true, true, false };
const static bool one[7] = { true, false, false, false, false, true, false };
const static bool two[7] = { true, true, false, true, true, false, true };
const static bool three[7] = { true, true, false, false, true, true, true };
const static bool four[7] = { true, false, true, false, false, true, true };
const static bool five[7] = { false, true, true, false, true, true, true };
const static bool six[7] = { false, true, true, true, true, true, true };
const static bool seven[7] = { true, true, false, false, false, true, false };
const static bool eight[7] = { true, true, true, true, true, true, true };
const static bool nine[7] = { true, true, true, false, true, true, true };

#define thick 3

class Text {
	Vector3 pos_vec;
	char ch;

public:
	Text(Vector3 pos_vec, char ch);
	void SetChar(char ch);
	void Draw();



};

#endif // !text_hpp
