//
//  Game.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 1/2/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include "object.hpp"
#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include "input.hpp"


class Game {
public:
    
    static Game* Instance(void);
    void Init(int _screen_height, int _screen_width, float _frame_rate);
    void Update(void);
    bool HandleEvents(void);
    void Draw(void);
    void Clean(void) { delete thisInstance; }
    
private:
    
    Game(void) {
        if(!al_init()){
            printf("Allegro didn't init.\n");
            exit(1);
        }
    }
    ~Game(void) {
        al_destroy_display(disp);
    }
    
    static Game* thisInstance;
    int screenWidth, screenHeight;
    float frameRate;
    
    std::vector<Object*> gameObjects;
    ALLEGRO_DISPLAY *disp;
    
};

typedef Game TheGame;

#endif /* Game_hpp */
