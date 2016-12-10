//
//  renderer.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "renderer.hpp"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

static ALLEGRO_COLOR color_white = al_map_rgb(255, 255, 255);

namespace Renderer {
    
    // 3 vertices and thickness -> 0 for filled.
    void draw_triangle(const Vector3& pt1, const Vector3& pt2,
                       const Vector3& pt3, float thickness) {
        if(thickness > 0) {
            al_draw_triangle(pt1.GetX(), pt1.GetY(),
                             pt2.GetX(), pt2.GetY(),
                             pt3.GetX(), pt3.GetY(),
                             color_white, thickness);
        }
        else {
            al_draw_filled_triangle(pt1.GetX(), pt1.GetY(),
                                    pt2.GetX(), pt2.GetY(),
                                    pt3.GetX(), pt3.GetY(),
                                    color_white);
        }
    }
    
    void draw_line(const Vector3& pt1, const Vector3& pt2, float thickness){
        al_draw_line(pt1.GetX(), pt1.GetY(),
                     pt2.GetX(), pt2.GetY(),
                     color_white, thickness);
    }
    
    //center, radius and thickness. Thickness 0 for filled.
    void draw_circle(const Vector3& center, float radius, float thickness){
        if(thickness > 0) {
            al_draw_filled_circle(center.GetX(), center.GetY(),
                                  radius, color_white);
        }
    }
    
    void draw_point(const Vector3& position) {
        al_draw_pixel(position.GetX(), position.GetY(), color_white);
    }
    
}

