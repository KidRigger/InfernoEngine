//
//  shots.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/10/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "shots.hpp"


Shot::Shot(const Vector3& position, const Vector3& direction,
           float move_speed, float radius):
pos(position), dir(direction), speed(move_speed), rad(radius) {}