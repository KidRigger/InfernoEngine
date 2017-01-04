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
    
    Renderer::render_init();
    gameObjects.push_back(new Player(_screen_width/2, _screen_height/2));
    
}

void Game::Update() {
    Collider::CollisionCheck(gameObjects);
    for(auto it = gameObjects.begin(); it != gameObjects.end(); ++it){
        (*it)->Update(1.0/frameRate);
    }
}

bool Game::HandleEvents() {
    TheInput::Instance()->Update();
    return !(TheInput::Instance()->GetInput(key_escape));
}

void Game::Draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for(auto it = gameObjects.begin(); it != gameObjects.end(); ++it){
        (*it)->Draw();
    }
    al_flip_display();
}