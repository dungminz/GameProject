#pragma once

#include <vector>
#include "Game.h"

struct Sprite {

    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFlame = 0;
    int flames;
    int ticks=0;

    void init(SDL_Texture *_texture, const int flames, const int _clips[][4]);
    void tick();
    void update();
    SDL_Rect *getSrc();

};
