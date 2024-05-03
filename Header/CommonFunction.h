#pragma once



const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~New Game~"


const int SPRITE_DELAY = 5;
const int STEPS_MOVE_BIRD = 4;
const int DISTANCE_TO_SCREEN = 10;

const double ENEMY_MIN_SPEED = 1;
const double ENEMY_MAX_SPEED = 5;

enum typeOfCharacror {
    EAGLE,
    EAGLECOLLAPSION,
    EGGBIRD,
    EGGBIRDCOLLAPSION,
    DIAMOND,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    EVILBIRDCOLLAPSION
};