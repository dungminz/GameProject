#include "../Header/Timer.h"


Timer::Timer() {
    start_tick = 0;
    paused_tick = 0;
    paused = started = false;
}

Timer::~Timer() {}


void Timer::start() {
    started = true;
    paused = false;
    start_tick = SDL_GetTicks();
}


void Timer::pause() {
    if(started == true && paused == false) {
        paused = true;
        paused_tick = SDL_GetTicks() - start_tick;
    }
}


void Timer::unpause() {
    if(paused == true) {
        paused = false;
        start_tick = paused_tick;
        paused_tick = 0;
    }
}


void Timer::stop() {
    paused = true;
    start_tick = false;
}


int Timer::getTicks() {
    if(started == true) {
        if(paused == true)
            return paused_tick;
        else 
            return SDL_GetTicks() - start_tick;
    }
    return -1;
}

void Timer::checkDelayFrame() {

    int real_time = getTicks();
    if(real_time < FRAME_MAX_DELAY) {
        int delay_time = FRAME_MAX_DELAY - real_time;
        SDL_Delay(delay_time);
        std::cerr<<"delay time : "<<delay_time<<'\n';
    }
}