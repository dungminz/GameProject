#include "../Header/Mouse.h"
#include "../Header/CommonFunction.h"


Mouse::Mouse() {}

Mouse::~Mouse() {
    x = y = w = h = dx = dy = speed = 0;
}


void Mouse::init(int _x, int _y, int _w, int _h) {

    x=_x, y=_y;
    w=_w, h=_h;
    dx=0; dy=0;
    speed = STEPS_MOVE_BIRD;
}


void Mouse::update() {

    // move();
    // dest = {x, y, w, h};
}


void Mouse::turnLeft()  {

    dx=-speed; dy=0; 
    move();
}


void Mouse::turnRight() {

    dx=speed; dy=0;
    move();
}


void Mouse::turnUp()    {

    dx=0; dy=-speed; 
    move();
}


void Mouse::turnDown()  {

    dx=0; dy=speed;  
    move();
}


void Mouse::move() {

    x+=dx; y+=dy;
}


SDL_Rect* Mouse::getDest() {

    dest = {x, y, w, h};
    return &dest;
}