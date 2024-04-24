#pragma once

#ifndef __has_extension
#define __has_extension(x) 0
#endif

#ifndef _GAME__H
#define _GAME__H

#include <SDL.h>
#include <SDL_image.h>
#include "../Header/DrawTexture.h"

void logErrorAndExit(const char* msg, const char* error);
void waitUntilKeyPressed();

struct Game {

    bool is_running;

    static bool leftPressed;
    static bool rightPressed;
    static bool upPressed;
    static bool downPressed;

    static SDL_Window *window;
    static SDL_Renderer *renderer;

    void init();
    void render();
    bool running() {return is_running;}
    void handle_events();
    void update();
    void clean();
};

#endif