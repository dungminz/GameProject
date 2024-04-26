#pragma once
#include "CommonFunction.h"
#include "Game.h"

struct DrawTexture {
    static SDL_Texture *loadTexture(const string filename);
    static void draw(SDL_Texture *texture);
    static void draw(SDL_Texture *texture, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, int x, int y);
};