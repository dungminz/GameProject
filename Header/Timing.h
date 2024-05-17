#pragma once

#ifndef __has_extension
#define __has_extension(x) 0
#endif

#include "SDL_stdinc.h"

struct Timing {

    Uint32 start_tick;
    Uint32 paused_tick;
    
    bool paused;
    bool started;
    
    Timing();
    ~Timing();
    
    void start();
    void stop();
    void reset();
    
    float getTicks();
    void DelayFrame();
};