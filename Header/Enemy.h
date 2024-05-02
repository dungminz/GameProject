#pragma once

#include "Game.h"
#include "Sprite.h"

const std::string DIAMOND_IMG = "../Image/Animation/diamond.png";
const int FLAMES_DIAMOND = 8;
const int DIAMOND_W = 576;
const int DIAMOND_H = 512;
const int DIAMOND_SCALE = 10;
const int DIAMOND_REAL_W = DIAMOND_W/DIAMOND_SCALE;
const int DIAMOND_REAL_H = DIAMOND_H/DIAMOND_SCALE;
const int RANGE_FLAME_DIAMOND = 165+576;
const int CLIPS_DIAMOND[FLAMES_DIAMOND][4] = {
    {70+RANGE_FLAME_DIAMOND*0, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*1, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*2, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*3, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*4, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*5, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*6, 0, 576, 512},
    {70+RANGE_FLAME_DIAMOND*7, 0, 576, 512}
};

struct Enemy {

    Enemy() {};

    SDL_Texture *enemy_img;
    int delay = 0;

    void init();
    void update();
    void update(Pos &pos);
    void render(int x, int y, int spr);

    Sprite enemy_spr;
};