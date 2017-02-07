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

/* 
 * Creates a new instance if not already existing
 * Else returns the current instance of the object itself
 */
ScoreManager* ScoreManager::Instance() {
    if(thisInstance == nullptr){
        thisInstance = new ScoreManager();
    }
    return thisInstance;
}

/* 
 * Constructor:
 * Creates a new score manager with the default initial settings.
 * It is only private and cannot be called by external functions.
 */
ScoreManager::ScoreManager() : score(0),max_score(0),lives(3),live_index(1) {}

void ScoreManager::SetScore(int score) {
    this->score = score;
}

/*
 * Increments the score and awards life at every 2000 points
 */
void ScoreManager::IncrementScore(int award) {
    this->score = this->score + award;
    if(score > live_index*2000){
        live_index++;
        lives++;
    }
}

/*
 * Takes away life at death and checks for gameover condition.
 */
void ScoreManager::DecrementLife() {
    lives--;
    if(lives == 0){
        TheGame::Instance()->GameOver();
    }
}

/*
 * Initializer:
 * Initializes the UI elements that are displayed.
 * Creates text-handlers for score, high_score and
 * the number of lives.
 * Also loads the previously saved highscore.
 */
void ScoreManager::Init(const Vector3& score_vec,
                        const Vector3& high_score,
                        const Vector3& life) {
    
    /* Text handler creation and storage into a map */
    std::unique_ptr<TextHandler> text_handler1(new TextHandler(score_vec,score));
    texts["score"] = std::move(text_handler1);
    std::unique_ptr<TextHandler> text_handler2(new TextHandler(high_score,
                                                               max_score));
    texts["high_score"] = std::move(text_handler2);
    std::unique_ptr<TextHandler> text_handler3(new TextHandler(life,lives));
    texts["lives"] = std::move(text_handler3);
    std::unique_ptr<TextHandler> text_handler4(
                                    new TextHandler((high_score - Vector3(300,0)),
                                                    "high score", 10));
    texts["hs_tag"] = std::move(text_handler4);
    
    /* Highs score loading using fstream */
    std::fstream save_file;
    save_file.open("asteroid_save.txt", std::ios::in);
    save_file >> max_score;
    save_file.close();
}

/*
 * Draws all the TextHandlers on the screen
 */
void ScoreManager::Draw() {
    for(auto it = texts.begin(); it != texts.end(); ++it){
        it->second->Draw();
    }
}

/*
 * Updates the score manager to keep the score
 * Checks and sets the highscore <max_score> if required
 */
void ScoreManager::Update() {
    /* Scorekeeping for the max_score */
    if(score > max_score){
        max_score = score;
    }
    
    /* Basic Updates */
    texts["score"]->SetNum(score);
    texts["high_score"]->SetNum(max_score);
    texts["lives"]->SetNum(lives);
}

/*
 * Cleaner:
 * Cleans the instance, directly deletes the instance
 * Memory de allocation is taken care of by the destructor.
 */
void ScoreManager::Clean() {
    delete thisInstance;
    thisInstance = nullptr;
}