  //
//  Game.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 1/2/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "Game.hpp"
#include "collision_manager.hpp"
#include <algorithm>
#include "Player.hpp"
#include "renderer.hpp"
#include "asteroid.hpp"
#include "input.hpp"
#include "score_manager.hpp"
#include "shots.hpp"
#include <allegro5/allegro_primitives.h>

Game* Game::thisInstance = nullptr;

Game* Game::Instance() {
    if (thisInstance == nullptr) {
        thisInstance = new Game();
    }
    return thisInstance;
}

void Game::Init(int _screen_width, int _screen_height, float _frame_rate) {
    
    screenWidth = _screen_width;
    screenHeight = _screen_height;
    frameRate = _frame_rate;
    disp = al_create_display(_screen_width,_screen_height);
    TheInput::Instance()->ResetMouse(disp);
    
    game_on = true;
    
    Renderer::render_init();
    gameObjects.push_back(new Player(_screen_width/2,
                                     _screen_height/2,
                                     0
                                     )
                          );
    
    SpawnAsteroid(Vector3::RandomInRange(screenWidth/2,screenWidth/2+30)
                    + Vector3(screenWidth/2, screenHeight/2));
    update_counter = 0;
    
    TheScoreManager::Instance()->Init(Vector3(20, 20), Vector3(screenWidth/2, 20), Vector3(20, 100));
    
}

void Game::Update() {
    Collider::CollisionCheck(gameObjects);
    for(auto it = gameObjects.begin(); it != gameObjects.end(); ++it){
        (*it)->Update(1.0/frameRate);
    }
    if((++update_counter)%((int)(frameRate)) == 0) {
        update_counter = 0;
        SpawnAsteroid(Vector3::RandomInRange(screenWidth/2+60,screenWidth/2+120) + Vector3(screenWidth/2, screenHeight/2));
    }
    TheScoreManager::Instance()->Update();
}

bool Game::HandleEvents() {
    
    //std::cout <<std::endl;
    TheInput::Instance()->Update();
    for(int i = 0; i != spawn_queue.size(); ++i)
    {
        spawn_queue[i]->ChangeID((int)gameObjects.size());
        gameObjects.push_back(spawn_queue[i]);
    }
    while (!spawn_queue.empty()) {
        spawn_queue.pop_back();
    }
    
    std::sort(del_ids.begin(), del_ids.end());
    
    for(auto it = del_ids.rbegin(); it!=del_ids.rend(); ++it)
    {
        gameObjects[*it]->ChangeID(gameObjects.back()->GetID());
        gameObjects.back()->ChangeID(*it);
        std::swap(gameObjects[*it],gameObjects[gameObjects.size()-1]);
        Object* object = gameObjects.back();
        gameObjects.pop_back();
        delete object;
    }
    del_ids.clear();
    return game_on && !(TheInput::Instance()->GetInput(key_escape));
}

void Game::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    for(auto it = gameObjects.begin(); it != gameObjects.end(); ++it){
        (*it)->Draw();
    }
    TheScoreManager::Instance()->Draw();
    
    al_flip_display();
}

void Game::Destroy(int id) {
    del_ids.push_back(id);
}

void Game::SpawnAsteroid(const Vector3& position,
                         Vector3 velocity,
                         float r, int lvl) {
    if(velocity.SqrMagnitude() == 0)
        velocity = Vector3(screenWidth/2,screenHeight/2)
                        + (Vector3::RandomInRange(screenHeight*0.66)
                        - position);
    auto aster = new Asteroid(position, int(gameObjects.size()+spawn_queue.size()), velocity.Normalized()*150, r);
    aster->SetChildLevel(lvl);
    spawn_queue.push_back(aster);
}

void Game::SpawnShot(const Vector3& position, Vector3 velocity) {
    auto sho = new Shot(position, velocity,
                        int(gameObjects.size()+spawn_queue.size())
                        );
    spawn_queue.push_back(sho);
}

void Game::Clean() {
    while(!gameObjects.empty()){
        delete gameObjects.back();
        gameObjects.pop_back();
    }
    delete thisInstance;
}
