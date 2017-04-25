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

class Game {
public:
    
    static Game* Instance(void);
    
    void Init(int _screen_height, int _screen_width, float _frame_rate);
    void Start(void);
    void Update(void);
    bool HandleEvents(void);
    void Draw(void);
    void Clean (void);
    
    
    int GetScreenWidth(void) {return screenWidth;}
    int GetScreenHeight(void) {return screenHeight;}
    
    void CallHit(int id) {
        if(id < gameObjects.size())
            gameObjects[id]->Hit();
        printf("Hit called on %i\n",id);  
    }
    
    void GameOver(void);
    
    void SpawnAsteroid(const Vector3& position,
                       Vector3 direction = Vector3(),
                       float r = 0, int lvl = 0);
    void SpawnUfo(const Vector3& position,
                       Vector3 direction = Vector3(),
                       float r = 0);
    void SpawnShot(int owner, const Vector3& position,
                   Vector3 velocity);
    void Destroy(int id);
    
    Vector3 playerLoc(){return gameObjects[0]->GetPosition();}
    
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
    
    bool game_on, full_screen;
    
    int update_counter;
    
    std::vector<Object*> gameObjects;
    ALLEGRO_DISPLAY *disp;
    
    std::vector<Object*> spawn_queue;
    std::vector<int> del_ids;
    
};

typedef Game TheGame;

#endif /* Game_hpp */
