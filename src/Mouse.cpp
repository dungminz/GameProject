#include "../Header/Mouse.h"

Mouse::Mouse() : x(100), y(100) {}

void Mouse::turnLeft()  {dx=-speed; dy=0; move();}
void Mouse::turnRight() {dx=speed; dy=0;  move();}
void Mouse::turnUp()    {dx=0; dy=-speed; move();}
void Mouse::turnDown()  {dx=0; dy=speed;  move();}

void Mouse::move() {x+=dx; y+=dy;}