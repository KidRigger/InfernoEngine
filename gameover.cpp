//
//  gameover.cpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 1/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#include "gameover.hpp"
#include <fstream>

GameOverScreen::GameOverScreen(int screenWidth, int screenHeight,
                               int score, int high_score) :
game_over_label(Vector3(screenWidth/2 - 135,screenHeight/2 - 60),"Game Over", 30),
score(Vector3(screenWidth/2, screenHeight/2 + 30), score, 10),
high_score(Vector3(screenWidth/2, screenHeight/2 + 60), high_score, 10),
score_label(Vector3(screenWidth/2 - 300, screenHeight/2 + 30), "Score ", 10),
high_score_label(Vector3(screenWidth/2 - 300, screenHeight/2 + 60),
                 "High Score ", 10),
replay(Vector3(screenWidth/2 - 125, screenHeight/2 + 150),
                "Press Enter to play again", 10),
exit(Vector3(screenWidth/2 - 125, screenHeight/2 + 180),
                "Press Escape to quit", 10)
{hsval = high_score;
    std::fstream save_file;
    save_file.open("asteroid_save.txt",
                   std::ios::trunc | std::ios::out);
    save_file << hsval << std::endl;
    save_file.close();
}

void GameOverScreen::Draw() {
    game_over_label.Draw();
    score_label.Draw();
    score.Draw();
    high_score_label.Draw();
    high_score.Draw();
    replay.Draw();
    exit.Draw();
}

GameOverScreen::~GameOverScreen() {
}
