#pragma once

#include "Game.h"
#include "Sprite.h"

const std::string EGGBIRD_IMG = "../Image/Animation/eggbird.png";
const int FLAMES_EGGBIRD = 8;
const int EGGBIRD_REAL_W = 560/8;
const int EGGBIRD_REAL_H = 420/8;
const int RANGE_FLAME_EGGBIRD = 800+560;
const int CLIPS_EGGBIRD[FLAMES_EGGBIRD][4] = {
    {405+RANGE_FLAME_EGGBIRD*0, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*1, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*2, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*3, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*4, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*5, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*6, 50, 560, 420},
    {405+RANGE_FLAME_EGGBIRD*7, 50, 560, 420},
};

const int MAIN_BIRD_ORIGIN_POS_X = 100;
const int MAIN_BIRD_ORIGIN_POS_Y = 100;

struct MainBird {

    MainBird();
    MainBird(Animation* bird);

    int x, y, w, h;
    SDL_Texture *bird_img;
    Animation* bird_ani;

    void init();
    void update();
    void render();

    Mouse bird_mouse;
    Sprite bird_spr;
};