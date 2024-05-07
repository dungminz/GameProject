#pragma once

#include "Game.h"


struct Mouse {

    int x, y, w, h;
    int dx, dy;
    int speed;
    SDL_Rect dest;

    Mouse();
    ~Mouse();

    void init(int _x, int _y, int _w, int _h);
    void update();

    void turnLeft();
    void turnRight(); 
    void turnUp();
    void turnDown();
    void move();

    SDL_Rect* getDest();
};