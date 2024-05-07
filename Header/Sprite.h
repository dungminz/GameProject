#pragma once

#include "Game.h"


struct Sprite {

    SDL_Texture* texture;
    SDL_Rect *clips;
    int currentFlame;
    int flames;
    int delay;

    Sprite();
    ~Sprite();

    void init(SDL_Texture *_texture, const int flames, const int _clips[][4]);
    void init(Animation* ani);
    void tick();
    void update();
    SDL_Rect *getSrc();

};