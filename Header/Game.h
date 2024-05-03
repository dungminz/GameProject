#pragma once

// #ifndef __has_extension
// #define __has_extension(x) 0
// #endif

#include <iostream>
#include <vector>
// #include <utility>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
// #include <SDL_ttf.h>
// #include <SDL_mixer.h>

#include "AnimationManager.h"
#include "TextureManager.h"
#include "Mouse.h"
#include "Sprite.h"

void logErrorAndExit(const char* msg, const char* error);
void waitUntilKeyPressed();

struct Pos {
    int x, y, spr;
    double speed;
    
    Pos(int _x, int _y, int _spr) 
        : x(_x), y(_y), spr(_spr) {}
    Pos(int _x, int _y, int _spr, double _speed) 
        : x(_x), y(_y), spr(_spr), speed(_speed) {}
};

struct Game {

    bool is_running;
    bool is_enemy;

    std::vector<Pos> diamond_pos;
    std::vector<Pos> diamondcollapsion_pos;
    std::vector<Pos> enemybird_pos;
    std::vector<Pos> enemybirdcollapsion_pos;

    static bool leftPressed;
    static bool rightPressed;
    static bool upPressed;
    static bool downPressed;

    static SDL_Window *window;
    static SDL_Renderer *renderer;

    void init(Animation* _mainbird, Animation* _supportbird, 
        Animation* _diamond, Animation* _diamond_collapsion, 
        Animation* _enemybird, Animation* _enemy_collapsion);
    void render();
    bool running() {return is_running;};
    void handle_events();
    bool collision(SDL_Rect* _bird, SDL_Rect* _enemybird);
    void checkCollision(SDL_Rect* _bird, std::vector<Pos> &enemy_pos, std::vector<Pos> &collapsion_pos);
    void update();
    void clean();

    void create_enemy(std::vector<Pos> &_pos, int numbers);
};