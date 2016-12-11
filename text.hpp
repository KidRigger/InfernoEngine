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

#define thick 3

#include "renderer.hpp"


const static Vector3 line[7][2] = { { Vector3(1,1),Vector3(1,0) },
                                    { Vector3(1,0),Vector3(0,0) },
                                    { Vector3(0,0),Vector3(0,1) },
                                    { Vector3(0,1),Vector3(0,2) },
                                    { Vector3(0,2),Vector3(1,2) },
                                    { Vector3(1,2),Vector3(1,1) },
                                    { Vector3(1,1),Vector3(0,1) }
                                };

//line 0 -> top right ,  go counterclockwise for others
//line 6 horizontal

const static bool numbers[10][7] = {
                            {  true,  true,  true,  true,  true,  true, false },
                            {  true, false, false, false, false,  true, false },
                            {  true,  true, false,  true,  true, false,  true },
                            {  true,  true, false, false,  true,  true,  true },
                            {  true, false,  true, false, false,  true,  true },
                            { false,  true,  true, false,  true,  true,  true },
                            { false,  true,  true,  true,  true,  true,  true },
                            {  true,  true, false, false, false,  true, false },
                            {  true,  true,  true,  true,  true,  true,  true },
                            {  true,  true,  true, false,  true,  true,  true }
                        };


class Text {
    	Vector3 pos_vec;
    	char ch;
        float size;
    
    public:
    	Text(Vector3 pos_vec, char ch, float size = 20);
        void SetChar(char ch);
    	void Draw();
};

#endif //text_hpp

//--------------------------------------------------------------------------------
