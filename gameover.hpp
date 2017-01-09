//
//  gameover.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 1/9/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef gameover_hpp
#define gameover_hpp

#include "texthandler.hpp"

class GameOverScreen {
public:
    GameOverScreen(int screenWidth, int screenHeight);
    ~GameOverScreen();
    void Draw();
private:
    TextHandler game_over_label;
    TextHandler score, score_label;
    TextHandler high_score, high_score_label;
};

#endif /* gameover_hpp */
