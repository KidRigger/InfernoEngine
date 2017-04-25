//--------------------------------------------------------------------------------
//
//  asteroid.cpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/10/16.
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "asteroid.hpp"
#include <stdlib.h>
#include <ctime>
#include "Game.hpp"
#include "score_manager.hpp"
#include "collision_manager.hpp"

//--------------------------------------------------------------------------------

Vector3 Asteroid::shape[3][10] = {
	{   Vector3(0.5,1.5), Vector3(1.5,1), Vector3(1,0.5), Vector3(2.5,0),
		Vector3(1.5,-1), Vector3(0.5,-1.5), Vector3(-1,-1), Vector3(-1,0),
		Vector3(-1.5,1), Vector3(-0.5,1)  },
	{   Vector3(0,2), Vector3(2,1), Vector3(2,-0.5), Vector3(1.5,-1.5),
		Vector3(0,-2), Vector3(-1.5,-1), Vector3(-1,-1), Vector3(-2,1),
		Vector3(-0.5,0.5), Vector3(-1,1.5) },
	{   Vector3(-0.5,2), Vector3(0.5,1.5), Vector3(1.5,2), Vector3(1,0.5),
		Vector3(1.5,-0.5), Vector3(1.5,-1.5), Vector3(0.5,-1), Vector3(0,-2),
		Vector3(-1.5,0), Vector3(-1.5,1.5) } };

//--------------------------------------------------------------------------------

Asteroid::Asteroid(const Vector3& pos_vec, int index, const Vector3& velocity, float radius):
pos_vec(pos_vec),
id(index),
radius(radius),
is_visible(false),
//reg_hit(false),
vel(velocity) {
    srand((int)time(0)+rand());

	if(this->radius == 0)
        this->radius = rand() % 20 + 15.0;

	angle = rand() % 360 + 0.0;

	shape_id = abs(rand()-rand())% 3;
    
    //printf("Asteroid %i\n",id);
}

void Asteroid::ChangeID(int id){
    this->id = id;
}

//--------------------------------------------------------------------------------

void Asteroid::Draw() {
    
	for (int i = 0; i < 9; i++) {
		Renderer::draw_line(pos_vec + shape[shape_id][i]*radius, pos_vec + shape[shape_id][i + 1]*radius, 3);
	}
	Renderer::draw_line(pos_vec + shape[shape_id][0]*radius, pos_vec + shape[shape_id][9]*radius, 3);
}

//--------------------------------------------------------------------------------

Vector3 Asteroid::GetPosition() const {
	return pos_vec;
}

float Asteroid::GetRadius() const {
	return 2*radius;
}

bool Asteroid::IsVisible() const {
    return is_visible;
}

//--------------------------------------------------------------------------------

void Asteroid::Update(float dt) {
    pos_vec = pos_vec + vel * dt;
    //std::cout << pos_vec << std::endl;
    if(is_visible && !Collider::OnScreen(this))
    {
        Destroy();
    }
    else if(!is_visible)
    {
        is_visible = Collider::OnScreen(this);
    }
}

//--------------------------------------------------------------------------------

void Asteroid::Destroy() {
    TheGame::Instance()->Destroy(id);
}

//--------------------------------------------------------------------------------

void Asteroid::Hit() {
    
    TheScoreManager::Instance()->IncrementScore(10);
    
    if(child_level != 2){
        TheGame::Instance()->SpawnAsteroid(pos_vec,
                                           vel + 0.5 * Vector3::Cross(vel, Vector3(0, 0, 1)),
                                           radius/1.4, child_level+1);
        TheGame::Instance()->SpawnAsteroid(pos_vec,
                                           vel + 0.5 * Vector3::Cross(vel, Vector3(0, 0, -1)),
                                           radius/1.4, child_level+1);
    }
    this->Destroy();
}
