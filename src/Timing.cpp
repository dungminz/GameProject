#include "../Header/Timing.h"
#include "../Header/Game.h"


Timing::Timing() {

    start_tick = 0;
    paused_tick = 0;
    paused = started = false;
}

Timing::~Timing() {}


void Timing::start() {

    started = true;
    paused = false;
    start_tick = SDL_GetTicks();
}

void Timing::stop() {
    paused = true;
    start_tick = false;
}

void Timing::reset() {
    start();
}


float Timing::getTicks() {
    if(started == true) {
        if(paused == true)
            return paused_tick;
        else 
            return SDL_GetTicks() - start_tick;
    }
    return -1;
}

void Timing::DelayFrame() {

    Uint32 real_time = getTicks();
    if(real_time < FRAME_MAX_DELAY) {
        float delay_time = FRAME_MAX_DELAY - real_time;
        SDL_Delay(delay_time);
    }
}