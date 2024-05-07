#pragma once

// #ifndef __has_extension
// #define __has_extension(x) 0
// #endif

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <SDL.h>
#include <SDL_image.h>
// #include <SDL_ttf.h>
// #include <SDL_mixer.h>

#include "Exception.h"
#include "BackgroundManager.h"
#include "AnimationManager.h"
#include "TextureManager.h"
#include "Mouse.h"
#include "Sprite.h"



struct Pos {
    int x, y, spr;
    double speed;
    
    Pos(int _x, int _y, int _spr) 
        : x(_x), y(_y), spr(_spr) {}
    Pos(int _x, int _y, int _spr, double _speed) 
        : x(_x), y(_y), spr(_spr), speed(_speed) {}
};


struct Game {

    static SDL_Window *window;
    static SDL_Renderer *renderer;

    GameState next_state;
    bool is_enemy;

    std::vector<Pos> diamond_pos;
    std::vector<Pos> diamondcollapsion_pos;
    std::vector<Pos> enemybird_pos;
    std::vector<Pos> enemybirdcollapsion_pos;

    Game();

    void init(BackgroundManager* _background, Animation* _mainbird, 
        Animation* _supportBird_flying, Animation* _supportBird_gothit, 
        Animation* _supportBird_shot, Animation* _supportBird_ram, 
        Animation* _supportBird_dead, Animation* _supportBird_henshin, 
        Animation* _supportBird_henshinshot, Animation* _collapsion_by_bird,
        Animation* _enemybird, Animation* _diamond, Animation* _diamond_collapsion);
    
    void render();
    void handle_events();
    void update();
    void clean();

    bool checkCollision(SDL_Rect* _char_first, SDL_Rect* _char_second);
    bool checkCollision(SDL_Rect* _bird, std::vector<Pos> &enemy_pos, 
                            std::vector<Pos> &collapsion_pos);
    void create_enemy(std::vector<Pos> &_pos, int numbers);
};