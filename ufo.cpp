//--------------------------------------------------------------------------------
//
//  ufo.cpp
//  InfernoEngine
//
//  Created by Ronak Harkhani on 12/12/16.
//  Completed by Anish Bhobe on 04/25/17
//  Copyright � 2016 Anish Bhobe. All rights reserved.
//
//--------------------------------------------------------------------------------

#include "ufo.hpp"
#include "Game.hpp"
#include "score_manager.hpp"

const static int thickness = 2;
const static Vector3 shape[8] = {
    Vector3(-0.375,-0.75), Vector3(0.375,-0.75),
    Vector3(0.75,-0.375) , Vector3(1.5,0),
    Vector3(0.875,0.375) , Vector3(-0.875,0.375),
    Vector3(-1.5,0)      , Vector3(-0.75,-0.375)
};


//--------------------------------------------------------------------------------

Ufo::Ufo(const Vector3& pos_vec, int index, const Vector3& velo, float radius, int shoot_delay):
pos_vec(pos_vec), vel(velo), radius(radius), id(index), update_counter(0), shoot_delay(shoot_delay) {
    if (radius == 0) {
        srand((int)time(0));
		this->radius = (rand() % 2 + 1)*20;
	}
}

//--------------------------------------------------------------------------------

Ufo::~Ufo(void){
    Object::~Object();
}

//--------------------------------------------------------------------------------

Vector3 Ufo::GetPosition(void) const {
    return pos_vec;
}

//--------------------------------------------------------------------------------

float Ufo::GetRadius() const {
	return radius;
}

//--------------------------------------------------------------------------------

void Ufo::Draw() {
	for (int i = 0; i != 7; ++i) {
		Renderer::draw_line(pos_vec+radius*shape[i], pos_vec+radius*shape[i + 1],
                            thickness);
	}
    Renderer::draw_line(pos_vec+radius*shape[7], pos_vec+radius*shape[0],
                        thickness);
	Renderer::draw_line(pos_vec+radius*shape[7], pos_vec+radius*shape[2],
                        thickness);
	Renderer::draw_line(pos_vec+radius*shape[6], pos_vec+radius*shape[3],
                        thickness);
}

//--------------------------------------------------------------------------------

void Ufo::Update(float dt){
    pos_vec = pos_vec + vel * dt;
    if(++update_counter%shoot_delay == 0){
        if(radius == 20) {
            TheGame::Instance()->SpawnShot(2, pos_vec, (TheGame::Instance()->playerLoc() - pos_vec).Normalized()*300);
        }
        else {
            TheGame::Instance()->SpawnShot(2, pos_vec, Vector3::RandomDirection()*300);
        }
        update_counter = 0;
    }
}

//--------------------------------------------------------------------------------

void Ufo::Hit(void) {
    TheScoreManager::Instance()->IncrementScore(50);
    TheGame::Instance()->Destroy(id);
}

//--------------------------------------------------------------------------------
