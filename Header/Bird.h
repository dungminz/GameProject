#pragma once

#include "Game.h"
#include "Mouse.h"
#include "Sprite.h"

const int FLAMES_DINO = 9;
const int SIZE_DINO = 57;
const int CLIPS_DINO[FLAMES_DINO][4] = {
    {SIZE_DINO*0, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*1, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*2, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*3, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*4, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*5, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*6, 0, SIZE_DINO, SIZE_DINO},
    {SIZE_DINO*7, 0, SIZE_DINO, SIZE_DINO}
};

const int FLAMES_EGG_BIRD = 8;
const int RANGE_FLAME_EGG_BIRD = 1360;
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

struct Bird {
    Bird();

    SDL_Texture *bird_img;

    void init();
    void update();
    void render();

    Mouse mouse;
    Sprite dino;
    Sprite bird;
};

