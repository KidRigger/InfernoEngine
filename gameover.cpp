//
//  gameover.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 1/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "gameover.hpp"

GameOverScreen::GameOverScreen(int screenWidth, int screenHeight,
                               int score, int high_score) :
game_over_label(Vector3(screenWidth/2, screenHeight/2),"Game Over"),
score(Vector3(screenWidth/2, screenHeight/2 + 60), score, 10),
high_score(Vector3(screenWidth/2, screenHeight/2 + 120), high_score, 10),
score_label(Vector3(screenWidth/2 - 300, screenHeight/2 + 60), "Score ", 10),
high_score_label(Vector3(screenWidth/2 - 300, screenHeight/2 + 120),
                 "High Score ", 10)
{}

void GameOverScreen::Draw() {
    game_over_label.Draw();
    score_label.Draw();
    score.Draw();
    high_score_label.Draw();
    high_score.Draw();
}

GameOverScreen::~GameOverScreen() {
    
}
