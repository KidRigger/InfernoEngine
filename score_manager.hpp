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

class ScoreManager {
public:
    static ScoreManager* Instance(void);
    
    void Init(const Vector3& score,
              const Vector3& high_score,
              const Vector3& life);
    
    void SetScore(int score);
    
    void IncrementScore(int award);
    
    void DecrementLife(void);
    
    void Update(void);
    
    void Draw(void);
    
    void Clean(void);
    
    int GetScore(void) { return score; }
    int GetHighScore(void) { return max_score; }
    
private:
    ScoreManager();
    ~ScoreManager() {texts.clear();}
    
    std::map<std::string, TextHandler*> texts;
    
    int score, max_score, lives;
    
    static ScoreManager* thisInstance;
};

typedef ScoreManager TheScoreManager;

#endif /* score_manager_hpp */
