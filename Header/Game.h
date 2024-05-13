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
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Exception.h"
#include "Timing.h"
#include "BackgroundManager.h"
#include "AnimationManager.h"
#include "Graphics.h"
#include "Mouse.h"
#include "Sprite.h"
#include "Enemy.h"



struct Game {

    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static TTF_Font *bigfont;
    static TTF_Font *mediumfont;
    static TTF_Font *smallfont;

    SDL_Texture *texture;
    GameState next_state;

    Game();
    ~Game();

    void init(BackgroundManager* _background, Animation* _mainbird, 
        Animation* _supportBird_flying, Animation* _supportBird_gothit, 
        Animation* _supportBird_shot, Animation* _supportBird_ram, 
        Animation* _supportBird_dead, Animation* _supportBird_henshin, 
        Animation* _supportBird_henshinshot, Animation* _collapsion_by_bird,
        Animation* _enemybird, Animation* _diamond, Animation* _diamond_collapsion);
    void handle_events();
    void update();
    void render();
    void clean();

    void initLogic();
    void updateLogic();
    void renderLogic();
    void free();

    bool checkCollision(SDL_Rect* _bird, class Enemy* _enemy);
    void checkAppear(Enemy* _enemy);
    void create_enemy(Enemy* _enemy, int numbers);
    bool noneEnemy();

    int score;
    int wave_num;
    int turn_num;
    int turn_diamond;
    int turn_enemybird;

    Timing time_turn;
    Timing time_wave;
};