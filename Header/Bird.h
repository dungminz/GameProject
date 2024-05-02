#pragma once

#include "Game.h"
#include "Sprite.h"

const std::string EGG_BIRD_IMG = "../Image/Animation/eggbird.png";
const int FLAMES_EGG_BIRD = 8;
const int EGG_BIRD_REAL_W = 560/8;
const int EGG_BIRD_REAL_H = 420/8;
const int RANGE_FLAME_EGG_BIRD = 800+560;
const int CLIPS_EGG_BIRD[FLAMES_EGG_BIRD][4] = {
    {405+RANGE_FLAME_EGG_BIRD*0, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*1, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*2, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*3, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*4, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*5, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*6, 50, 560, 420},
    {405+RANGE_FLAME_EGG_BIRD*7, 50, 560, 420},
};

const int MAIN_BIRD_ORIGIN_POS_X = 100;
const int MAIN_BIRD_ORIGIN_POS_Y = 100;

struct Bird {
    Bird();

    int x, y, w, h;
    SDL_Texture *bird_img;

    void init();
    void update();
    void render();

    Mouse bird_mouse;
    Sprite bird_spr;
};