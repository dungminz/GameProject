#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~New Game~"

const int EGGBIRD_SCALE = 6;
const int COLLAPSION_BY_EAGLE_SCALE = 2;
const int DIAMOND_SCALE = 10;
const int DIAMONDCOLLAPSION_SCALE = 3;
const double EVILBIRD_SCALE = 3.75;

const int MAIN_BIRD_ORIGIN_POS_X = 100;
const int MAIN_BIRD_ORIGIN_POS_Y = 100;

const int SPRITE_DELAY = 5;
const int STEPS_MOVE_BIRD = 4;
const int DISTANCE_TO_SCREEN = 10;

const double ENEMY_MIN_SPEED = 1;
const double ENEMY_MAX_SPEED = 5;

enum typeOfCharacror {
    EAGLE,
    EAGLECOLLAPSION,
    COLLAPSIONBYEAGLE,
    EGGBIRD,
    EGGBIRDCOLLAPSION,
    DIAMOND,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    EVILBIRDCOLLAPSION
};