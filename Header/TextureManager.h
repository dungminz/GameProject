#pragma once
#include "Game.h"

struct TextureManager {
    static SDL_Texture *loadTexture(const std::string filename);
    static void draw(SDL_Texture *texture);
    static void draw(SDL_Texture *texture, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
};