//
//  main.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 10/20/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "Game.hpp"
#include "gameover.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "score_manager.hpp"

int main(int argc, char ** argv) {
    
    //Game loop goes here
    
    TheGame::Instance()->Init(1440,900,60);
    TheGame::Instance()->Start(); 
    while(TheGame::Instance()->HandleEvents()){
        TheGame::Instance()->Update();
        TheGame::Instance()->Draw();
        al_rest(1.0/60);
    }
    TheGame::Instance()->Clean();
    
    
    
    return 0;
}
