#pragma once

const int INITIAL_SPEED = 4;

struct Mouse {

    Mouse();

    int x, y;
    int dx=0, dy=0;
    int speed = INITIAL_SPEED;

    void turnLeft();
    void turnRight(); 
    void turnUp();
    void turnDown();

    void move();

};