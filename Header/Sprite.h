#pragma once

#include "Game.h"


struct Sprite {

    SDL_Texture* texture;
    SDL_Rect *clips;
    int currentFrame;
    int frames;
    int delay;

    Sprite();
    ~Sprite();

    void init(Animation* ani);
    void tick();
    void update();
    SDL_Rect *getSrc();

};