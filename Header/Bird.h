#pragma once

#include "Game.h"
#include "Mouse.h"
#include "Sprite.h"

const int TOTAL_FLAME_DINO = 9;
const int SIZE_DINO = 57;
const int DINO_CLIPS[TOTAL_FLAME_DINO][4] = {
    {SIZE_DINO*0, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*1, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*2, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*3, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*4, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*5, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*6, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*7, 0, SIZE_DINO, SIZE_DINO}
};

struct Bird {
    Bird();

    SDL_Texture *bird_img;
    SDL_Texture *dino_img;

    void init();
    void update();
    void render();

    Mouse mouse;
    Sprite dino;
};

