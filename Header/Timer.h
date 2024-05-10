#pragma once

#include "Game.h"

struct Timer {

    int start_tick;
    int paused_tick;
    
    bool paused;
    bool started;
    
    Timer();
    ~Timer();
    
    void start();
    void stop();
    void pause();
    void unpause();
    
    int getTicks();
    void checkDelayFrame();
};