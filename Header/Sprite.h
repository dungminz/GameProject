#pragma once

#include "Game.h"


struct Sprite {

    Timing time_sprite;
    SDL_Texture* texture;
    SDL_Rect *clips;
    int currentFrame;
    int numFrames;

    Sprite();
    Sprite(Animation* ani);
    ~Sprite();

    void init();
    void tick();
    void update();
    SDL_Rect *getSrc();
};