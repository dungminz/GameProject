#pragma once

#ifndef __has_extension
#define __has_extension(x) 0
#endif

// #include <stdint.h>
#include "SDL_stdinc.h"
// #include "Game.h"

struct Timing {

    Uint32 start_tick;
    Uint32 paused_tick;
    
    bool paused;
    bool started;
    
    Timing();
    ~Timing();
    
    void start();
    void stop();
    void pause();
    void unpause();
    void reset();
    
    float getTicks();
    void checkDelayFrame();
};