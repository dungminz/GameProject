#pragma once

#include "Game.h"


struct TextureManager {
            
    static SDL_Texture *loadTexture(const std::string filename);

    static void draw(SDL_Texture *texture);
    static void drawBackground(SDL_Texture *texture, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    static void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);
    static void drawAngle(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest, double angle);
    static void drawIcon(SDL_Texture *texture, int x, int y);

    static SDL_Texture* loadTexture(const std::string filename, 
                        TTF_Font* font, SDL_Color textColor);
    static void drawText(SDL_Texture *texture, int x, int y);
};