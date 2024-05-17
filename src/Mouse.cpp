#include "../Header/Mouse.h"
#include "../Header/CommonFunction.h"


Mouse::Mouse() {}

Mouse::Mouse(SDL_Rect _dest) 
    : curr_bird(_dest),
    dx(0), dy(0),
    speed(STEPS_MOVE_BIRD),
    angle(0) {}

Mouse::~Mouse() {}


void Mouse::getOtherBird(SDL_Rect _dest) {
    other_bird = _dest;
}

void Mouse::handleEventsMainBird(SDL_Event& event) {

    switch(event.type) {

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_a: bird_left=true;  bird_right=false; break;
                case SDLK_d: bird_right=true; bird_left=false;  break;
                case SDLK_w: bird_up=true;    bird_down=false;  break;
                case SDLK_s: bird_down=true;  bird_up=false;    break;
                default: break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_a: bird_left=false;  break;
                case SDLK_d: bird_right=false; break;
                case SDLK_w: bird_up=false;    break;
                case SDLK_s: bird_down=false;  break;
                default: break;
            }
            break;

        default: break;
    }
}

void Mouse::handleEventsSupportBird(SDL_Event& event){

    switch(event.type) {

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  bird_left=true;  bird_right=false; break;
                case SDLK_RIGHT: bird_right=true; bird_left=false;  break;
                case SDLK_UP:    bird_up=true;    bird_down=false;  break;
                case SDLK_DOWN:  bird_down=true;  bird_up=false;    break;
                default: break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  bird_left=false;  break;
                case SDLK_RIGHT: bird_right=false; break;
                case SDLK_UP:    bird_up=false;    break;
                case SDLK_DOWN:  bird_down=false;  break;
                default: break;
            }
            break;

        default: break;
    }
}


void Mouse::update() {

    if(bird_left) turnLeft();
    if(bird_right) turnRight();
    if(bird_up) turnUp();
        else if(angle<0) angle+=ANGLE_STEP;
    if(bird_down) turnDown();
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

    int x_move=curr_bird.x+dx; 
    int y_move=curr_bird.y+dy;

    if(checkIntersection(x_move, y_move))
    {
        curr_bird.x=x_move;
        curr_bird.y=y_move;
    }
}

bool Mouse::checkIntersection(int x_move, int y_move) {

    if(x_move < DISTANCE_TO_SCREEN
    || x_move > SCREEN_WIDTH - curr_bird.w - DISTANCE_TO_SCREEN
    || y_move < DISTANCE_TO_SCREEN
    || y_move > SCREEN_HEIGHT - curr_bird.h - DISTANCE_TO_SCREEN)
        return false;

    // SDL_Rect dest_move({x_move, y_move, curr_bird.w, curr_bird.h});
    // if(SDL_HasIntersection(&dest_move, &other_bird))
    //     return false;

    return true;
}


SDL_Rect* Mouse::getDest() {

    return &curr_bird;
}