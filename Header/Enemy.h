#pragma once

#include "Game.h"

const int FLAMES_DIAMOND = 8;
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

    SDL_Texture *diamond_img;

    void init();
    void update();
    void render();
    void checkCollision();

    Sprite diamond;
};