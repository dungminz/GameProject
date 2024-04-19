#pragma once
#ifndef _GAME__H
#define _GAME__H

#include <SDL.h>
#include <SDL_image.h>
#include "../Header/TextureManager.h"

void logErrorAndExit(const char* msg, const char* error);
void waitUntilKeyPressed();

struct Game {

    SDL_Texture *bird;
    SDL_Texture *bgr;

    static SDL_Window *window;
    static SDL_Renderer *renderer;

    void init();
    void render();
    void render2();
    void clean();
};

#endif