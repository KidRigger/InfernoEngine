//
//  score_manager.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/21/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#include "score_manager.hpp"
#include "Game.hpp"

ScoreManager* ScoreManager::thisInstance = nullptr;

ScoreManager* ScoreManager::Instance() {
    if(thisInstance == nullptr){
        thisInstance = new ScoreManager();
    }
    return thisInstance;
}

ScoreManager::ScoreManager() : score(0),max_score(0),lives(3) {}

void ScoreManager::SetScore(int score) {
    this->score = score;
}

void ScoreManager::IncrementScore(int award) {
    this->score = this->score + award;                            
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
    TextHandler* text_handler = new TextHandler(score,this->score);
    texts["score"] = text_handler;
    text_handler = new TextHandler(high_score,max_score);
    texts["high_score"] = text_handler;
    text_handler = new TextHandler(life,lives);
    texts["lives"] = text_handler;
    text_handler = new TextHandler(high_score - Vector3(300,0),
                                   "high score", 10);
    texts["hs_tag"] = text_handler;
}

void ScoreManager::Draw() {
    for(auto it = texts.begin(); it != texts.end(); ++it){
        it->second->Draw();
    }
}

void ScoreManager::Update() {
    if(score > max_score){
        max_score = score;
    }
    texts["score"]->SetNum(score);
    texts["high_score"]->SetNum(max_score);
    texts["lives"]->SetNum(lives);
}