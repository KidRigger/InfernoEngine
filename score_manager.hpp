//
//  score_manager.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 12/21/16.
//  Copyright © 2016 Anish Bhobe. All rights reserved.
//

#ifndef score_manager_hpp
#define score_manager_hpp

#include <map>
#include "texthandler.hpp"
#include <memory>

class ScoreManager {
public:
    static ScoreManager* Instance(void);
    
    /* Creates the required UI elements */
    void Init(const Vector3& score,
              const Vector3& high_score,
              const Vector3& life);
    
    /* Sets the score */
    void SetScore(int score);
    
    /* Increases the score by 'award' and modifies the highscore */
    void IncrementScore(int award);
    
    /* Reduces life and checks for gameover */
    void DecrementLife(void);
    
    /* Updates the scores on the UI */
    void Update(void);
    
    /* Draws the UI elements of the scores */
    void Draw(void);
    
    /* Cleans the instance */
    void Clean(void);
    
    /* Returns the score of the player */
    int GetScore(void) { return score; }
    
    /* Returns the highscore of the game */
    int GetHighScore(void) { return max_score; }
    
private:
    ScoreManager();
    ~ScoreManager() {
        texts.clear();
    }
    
    /* Map to keep the text_handlers on the UI */
    std::map<std::string, std::unique_ptr<TextHandler> > texts;
    
    /*
     * score is the score
     * max_score is the high score
     * lives is the number of lives left i.e. the number...
     * ...of times the player can die
     * live_index is used to multiply the score requirement...
     * ...to award life at every 2000 points.
     */
    int score, max_score, lives, live_index;
    
    /* Stores the current instance of the object */
    static ScoreManager* thisInstance;
};

typedef ScoreManager TheScoreManager;

#endif /* score_manager_hpp */
