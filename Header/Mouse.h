#pragma once

#include "Game.h"

struct Mouse {

    Mouse();
    Mouse(int _x, int _y, int _w, int _h);

    int x, y, w, h;
    int dx, dy;
    int speed;
    SDL_Rect dest;

    void turnLeft();
    void turnRight(); 
    void turnUp();
    void turnDown();
    void move();

    void update();

    SDL_Rect* getDest();
};