#pragma once

#include "Game.h"

const int INITIAL_DISTANCE = 3;

struct Background {
    
    SDL_Texture *texture;
    int width, height;
    int scrollingOffset =0;
    
    void init();
    void scroll(int distance);
    void render();
};