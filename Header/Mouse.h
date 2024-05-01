#pragma once

#include "Game.h"

const int INITIAL_SPEED = 4;

struct Mouse {

    Mouse();
    Mouse(int _x, int _y, int _w, int _h);

    int x, y, w, h;
    int dx=0, dy=0;
    int speed = INITIAL_SPEED;
    SDL_Rect dest;

    void turnLeft();
    void turnRight(); 
    void turnUp();
    void turnDown();
    void move();

    void update();

    SDL_Rect* getDest();
};