#pragma once

#include "Game.h"
#include "Sprite.h"

const std::string EGGBIRD_IMG = "../Image/Animation/eggbird.png";
const int FLAMES_EGGBIRD = 8;
const int EGGBIRD_W = 560;
const int EGGBIRD_H = 420;
const int EGGBIRD_REAL_W = EGGBIRD_W/EGGBIRD_SCALE;
const int EGGBIRD_REAL_H = EGGBIRD_H/EGGBIRD_SCALE;
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

const std::string COLLAPSION_BY_EAGLE_IMG = "../Image/Animation/explosion_eagle.png";
const int FLAMES_COLLAPSION_BY_EAGLE = 8;
const int COLLAPSION_BY_EAGLE_W = 224;
const int COLLAPSION_BY_EAGLE_H = 224;
const int COLLAPSION_BY_EAGLE_REAL_W = COLLAPSION_BY_EAGLE_W/COLLAPSION_BY_EAGLE_SCALE;
const int COLLAPSION_BY_EAGLE_REAL_H = COLLAPSION_BY_EAGLE_H/COLLAPSION_BY_EAGLE_SCALE;
const int RANGE_FLAME_COLLAPSION_BY_EAGLE = 224;
const int CLIPS_COLLAPSION_BY_EAGLE[FLAMES_COLLAPSION_BY_EAGLE][4] = {
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*0, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*1, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*2, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*3, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*4, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*5, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*6, 0, 224, 224},
    {RANGE_FLAME_COLLAPSION_BY_EAGLE*7, 0, 224, 224},
};



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