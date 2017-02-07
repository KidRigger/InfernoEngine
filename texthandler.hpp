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
#include <vector>
#include "vector3.hpp"

/*
 * Texthandler is a class that stores a string or num for display...
 * ...at particular positions on the screen and can be repeatedly updated.
 * Texthndler is set up as a sequence of Text UI elements placed by the handler...
 * ...according to the space.
 */

class TextHandler {
public:
    /* Integer initialization ctor */
	TextHandler(Vector3 pos_vec, int num, int size = 20);
    /* String initialization ctor */
    TextHandler(Vector3 pos_vec, std::string str, int size = 20);
    /* Sets string value */
	void SetString(std::string str);
    /* Sets integer value */
	void SetNum(int num);
    /* Draw to the screen */
	void Draw();
private:
    /* Position of the entire element */
    Vector3 pos_vec;
    /* String value of the Text handler */
    std::string str;
    /* A vector containing the individual text elements */
    std::vector<Text> t;
    /* size is length of the string and the dim_size is thickness of the text */
    int size, dim_size;
};


#endif // !texthandler_hpp

//--------------------------------------------------------------------------------
