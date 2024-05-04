#pragma once

#include "Game.h"

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


const std::string EAGLE_IMG = "../Image/Animation/eagle.png";
const int EAGLE_SCALE = 1;
const int EAGLE_W = 121;
const int EAGLE_H = 85;
const int EAGLE_REAL_W = EAGLE_W/EAGLE_SCALE;
const int EAGLE_REAL_H = EAGLE_H/EAGLE_SCALE;
const int EAGLE_0 = 117;
const int EAGLE_1 = 201;
const int EAGLE_2 = 292;
const int EAGLE_3 = 383;
const int EAGLE_4 = 471;
const int EAGLE_5 = 563;
const int EAGLE_6 = 648;
const int EAGLE_7 = 738;


const int FLAMES_EAGLE_FLYING = 8;
const int RANGE_FLAME_EAGLE_FLYING = 134;
const int CLIPS_EAGLE_FLYING[FLAMES_EAGLE_FLYING][4] = {
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_2, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_3, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_4, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_5, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_6, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_FLYING, EAGLE_7, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_GOT_HIT = 8;
const int RANGE_FLAME_EAGLE_GOT_HIT = 274;
const int CLIPS_EAGLE_GOT_HIT[FLAMES_EAGLE_GOT_HIT][4] = {
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_2, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_3, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_4, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_5, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_6, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_GOT_HIT, EAGLE_7, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_SHOT = 3;
const int RANGE_FLAME_EAGLE_SHOT = 426;
const int CLIPS_EAGLE_SHOT[FLAMES_EAGLE_SHOT][4] = {
    {RANGE_FLAME_EAGLE_SHOT, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_SHOT, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_SHOT, EAGLE_2, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_RAM = 8;
const int RANGE_FLAME_EAGLE_RAM = 574;
const int CLIPS_EAGLE_RAM[FLAMES_EAGLE_RAM][4] = {
    {RANGE_FLAME_EAGLE_RAM, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_2, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_3, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_4, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_5, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_6, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_RAM, EAGLE_7, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_DEAD = 8;
const int RANGE_FLAME_EAGLE_DEAD = 723;
const int CLIPS_EAGLE_DEAD[FLAMES_EAGLE_DEAD][4] = {
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_2, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_3, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_4, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_5, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_6, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_DEAD, EAGLE_7, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_HENSHIN = 8;
const int RANGE_FLAME_EAGLE_HENSHIN = 872;
const int CLIPS_EAGLE_HENSHIN[FLAMES_EAGLE_HENSHIN][4] = {
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_2, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_3, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_4, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_5, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_6, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN, EAGLE_7, EAGLE_W, EAGLE_H},
};

const int FLAMES_EAGLE_HENSHIN_SHOT = 3;
const int RANGE_FLAME_EAGLE_HENSHIN_SHOT = 1018;
const int CLIPS_EAGLE_HENSHIN_SHOT[FLAMES_EAGLE_HENSHIN_SHOT][4] = {
    {RANGE_FLAME_EAGLE_HENSHIN_SHOT, EAGLE_0, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN_SHOT, EAGLE_1, EAGLE_W, EAGLE_H},
    {RANGE_FLAME_EAGLE_HENSHIN_SHOT, EAGLE_2, EAGLE_W, EAGLE_H},
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