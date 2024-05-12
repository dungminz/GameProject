#pragma once

#include "Game.h"


struct Mouse {

    int dx, dy;
    int speed;
    int angle;
    SDL_Rect curr_bird;
    SDL_Rect other_bird;

    bool bird_left;
    bool bird_right;
    bool bird_up;
    bool bird_down;

    Mouse();
    Mouse(SDL_Rect _dest);
    ~Mouse();

    void getOtherBird(SDL_Rect _dest);
    void handleEventsMainBird(SDL_Event& event);
    void handleEventsSupportBird(SDL_Event& event);
    void update();

    void turnLeft();
    void turnRight(); 
    void turnUp();
    void turnDown();
    void move();
    bool checkIntersection(int x_move, int y_move);

    SDL_Rect* getDest();
};