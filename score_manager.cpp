//
//  score_manager.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/21/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "score_manager.hpp"
#include "Game.hpp"
#include <fstream>

ScoreManager* ScoreManager::thisInstance = nullptr;

ScoreManager* ScoreManager::Instance() {
    if(thisInstance == nullptr){
        thisInstance = new ScoreManager();
    }
    return thisInstance;
}

ScoreManager::ScoreManager() : score(0),max_score(0),lives(3),live_index(1) {}

void ScoreManager::SetScore(int score) {
    this->score = score;
}

void ScoreManager::IncrementScore(int award) {
    this->score = this->score + award;
    if(score > live_index*2000){
        live_index++;
        lives++;
    }
    //printf("%i\n",score);
}

void ScoreManager::DecrementLife() {
    lives--;
    if(lives == 0){
        TheGame::Instance()->GameOver();
    }
    printf("Lost life\n");
}

void ScoreManager::Init(const Vector3& score,
                        const Vector3& high_score,
                        const Vector3& life) {
    TextHandler text_handler1(score,this->score);
    /* 
     * This is where all the problem exists.
     * Giving us bad access thread
     * Score is probably not cleared.
     */
    texts["score"] = text_handler1;
    TextHandler text_handler2(high_score,max_score);
    texts["high_score"] = text_handler2;
    TextHandler text_handler3(life,lives);
    texts["lives"] = text_handler3;
    TextHandler text_handler4((high_score - Vector3(300,0)),"high score", 10);
    texts["hs_tag"] = text_handler4;
    
    std::fstream save_file;
    save_file.open("asteroid_save.txt", std::ios::in);
    save_file >> max_score;
    save_file.close();
}

void ScoreManager::Draw() {
    for(auto it = texts.begin(); it != texts.end(); ++it){
        it->second.Draw();
    }
}

void ScoreManager::Update() {
    if(score > max_score){
        max_score = score;
    }
    texts["score"].SetNum(score);
    texts["high_score"].SetNum(max_score);
    texts["lives"].SetNum(lives);
}

void ScoreManager::Clean() {
    delete thisInstance;
    thisInstance = nullptr;
}