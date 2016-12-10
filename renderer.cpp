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
static const int origin_screen_x = 1440, origin_screen_y = 900;
static float scale_factor_x = 1, scale_factor_y = 1;

namespace Renderer {
    
    void render_scale(int screen_width, int screen_height){
        scale_factor_x = (screen_width/origin_screen_x);
        scale_factor_y = (screen_height/origin_screen_y);
    }
    
    // 3 vertices and thickness -> 0 for filled.
    void draw_triangle(const Vector3& pt1, const Vector3& pt2,
                       const Vector3& pt3, float thickness) {
        if(thickness > 0) {
            al_draw_triangle(pt1.GetX()*scale_factor_x, pt1.GetY()*scale_factor_y,
                             pt2.GetX()*scale_factor_x, pt2.GetY()*scale_factor_y,
                             pt3.GetX()*scale_factor_x, pt3.GetY()*scale_factor_y,
                             color_white, thickness);
        }
        else {
            al_draw_filled_triangle(pt1.GetX()*scale_factor_x, //pt1
                                    pt1.GetY()*scale_factor_y,
                                    pt2.GetX()*scale_factor_x, //pt2
                                    pt2.GetY()*scale_factor_y,
                                    pt3.GetX()*scale_factor_x, //pt3
                                    pt3.GetY()*scale_factor_y,
                                    
                                    color_white);
        }
    }
    
    void draw_line(const Vector3& pt1, const Vector3& pt2, float thickness){
        al_draw_line(pt1.GetX()*scale_factor_x, pt1.GetY()*scale_factor_y,
                     pt2.GetX()*scale_factor_x, pt2.GetY()*scale_factor_y,
                     color_white, thickness);
    }
    
    //center, radius and thickness. Thickness 0 for filled.
    void draw_circle(const Vector3& center, float radius, float thickness){
        if(thickness > 0) {
            al_draw_filled_circle(center.GetX()*scale_factor_x,
                                  center.GetY()*scale_factor_y,
                                  radius, color_white);
        }
    }
    
    void draw_point(const Vector3& position) {
        al_draw_pixel(position.GetX()*scale_factor_x,
                      position.GetY()*scale_factor_y,
                      color_white);
    }
    
}

