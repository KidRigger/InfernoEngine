//
//  renderer.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef renderer_hpp
#define renderer_hpp

#include "vector3.hpp"

namespace Renderer {
    
    void render_init(void);
    
    void render_scale(int screen_width, int screen_height);
    
    // 3 vertices and thickness -> 0 for filled.
    void draw_triangle(const Vector3& pt1, const Vector3& pt2,
                       const Vector3& pt3, float thickness = 0);
    
    void draw_line(const Vector3& pt1, const Vector3& pt2, float thickness = 2);
    
    //center, radius and thickness. Thickness 0 for filled.
    void draw_circle(const Vector3& center, float radius, float thickness = 0);
    
    void draw_point(const Vector3& position);
    
    float* get_screen_size();

}

#endif /* renderer_hpp */
