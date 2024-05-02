#pragma once

// #ifndef __has_extension
// #define __has_extension(x) 0
// #endif

#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "DrawTexture.h"
#include "Mouse.h"
#include "Sprite.h"

struct Enemy;
struct Bird;

// #include "Enemy.h"
// #include "Bird.h"

void logErrorAndExit(const char* msg, const char* error);
void waitUntilKeyPressed();

struct Pos {
    int x, y, spr;
};

struct Game {

    bool is_running;
    bool is_enemy;
    std::vector<Pos> diamond_pos;

    static bool leftPressed;
    static bool rightPressed;
    static bool upPressed;
    static bool downPressed;

    static SDL_Window *window;
    static SDL_Renderer *renderer;

    void init();
    void render();
    bool running() {return is_running;};
    void handle_events();
    bool checkCollision(SDL_Rect* _bird, SDL_Rect* _enemy);
    void update();
    void clean();

};