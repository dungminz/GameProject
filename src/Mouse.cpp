#include "../Header/Mouse.h"
#include "../Header/CommonFunction.h"

Mouse::Mouse() 
    : x(100), y(100), w(0), h(0) {}

Mouse::Mouse(int _x, int _y, int _w, int _h) 
    : x(_x), y(_y), w(_w), h(_h) 
    {
        dx=0, dy=0, speed = STEPS_MOVE;
    }

void Mouse::turnLeft()  {
    dx=-speed; dy=0; move();
}
void Mouse::turnRight() {
    dx=speed; dy=0;  move();
}
void Mouse::turnUp()    {
    dx=0; dy=-speed; move();
}
void Mouse::turnDown()  {
    dx=0; dy=speed;  move();
}
void Mouse::move() {
    x+=dx; y+=dy;
}

void Mouse::update() {
    if(Game::leftPressed) turnLeft();
    if(Game::rightPressed) turnRight();
    if(Game::upPressed) turnUp();
    if(Game::downPressed) turnDown();
    dest = {x, y, w, h};
}

SDL_Rect* Mouse::getDest() {
    return &dest;
}