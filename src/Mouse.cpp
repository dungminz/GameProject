#include "../Header/Mouse.h"
#include "../Header/CommonFunction.h"


Mouse::Mouse() {}

Mouse::~Mouse() {
    x = y = w = h = dx = dy = speed = angle = 0;
}


void Mouse::init(int _x, int _y, int _w, int _h) {

    x=_x, y=_y;
    w=_w, h=_h;
    dx=0; dy=0;
    speed = STEPS_MOVE_BIRD;
    angle = 0;
}


void Mouse::updateMainBird() {

    if(KeyPressed::mainbird_left) turnLeft();
    if(KeyPressed::mainbird_right) turnRight();
    if(KeyPressed::mainbird_up) turnUp();
        else if(angle<0) angle+=ANGLE_STEP;
    if(KeyPressed::mainbird_down) turnDown();
        else if(angle>0) angle-=ANGLE_STEP;
}


void Mouse::updateSupportBird() {
    
    if(KeyPressed::supportbird_left) turnLeft();
    if(KeyPressed::supportbird_right) turnRight();
    if(KeyPressed::supportbird_up) turnUp();
        else if(angle<0) angle+=ANGLE_STEP;
    if(KeyPressed::supportbird_down) turnDown();
        else if(angle>0) angle-=ANGLE_STEP;
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
    angle-=ANGLE_STEP;
    if(angle<-MAX_ANGLE) angle=-MAX_ANGLE;
    move();
}


void Mouse::turnDown()  {

    dx=0; dy=speed;
    angle+=ANGLE_STEP;
    if(angle>MAX_ANGLE) angle=MAX_ANGLE;
    move();
}


void Mouse::move() {

    x+=dx; y+=dy;
}


SDL_Rect* Mouse::getDest() {

    dest = {x, y, w, h};
    return &dest;
}