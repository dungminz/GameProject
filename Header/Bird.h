#pragma once

#include "Game.h"
#include "Mouse.h"

struct Bird {
    Bird();

    SDL_Texture *bird_img;

    void init();
    void update();
    void render();

    Mouse mouse;
};