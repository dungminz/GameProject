#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~New Game~"

const std::string EAGLE_IMG = "../Image/Animation/eagle.png";
const int EAGLE_SCALE = 1;
const int EAGLE_W = 121;
const int EAGLE_H = 85;
const int EAGLE_REAL_W = EAGLE_W/EAGLE_SCALE;
const int EAGLE_REAL_H = EAGLE_H/EAGLE_SCALE;
const int EAGLE_0 = 117;
const int EAGLE_1 = 201;
const int EAGLE_2 = 292;
const int EAGLE_3 = 383;
const int EAGLE_4 = 471;
const int EAGLE_5 = 563;
const int EAGLE_6 = 648;
const int EAGLE_7 = 738;

const double EGGBIRD_SCALE = 6;
const double COLLAPSION_BY_EAGLE_SCALE = 1.9;
const double DIAMOND_SCALE = 10;
const double DIAMONDCOLLAPSION_SCALE = 2.5;
const double EVILBIRD_SCALE = 3.75;

const int MAIN_BIRD_ORIGIN_POS_X = 100;
const int MAIN_BIRD_ORIGIN_POS_Y = 100;

const int SPRITE_DELAY = 5;
const int STEPS_MOVE_BIRD = 4;
const int DISTANCE_TO_SCREEN = 15;

const double ENEMY_MIN_SPEED = 1;
const double ENEMY_MAX_SPEED = 5;

enum typeOfCharacror {
    EAGLE,
    EAGLECOLLAPSION,
    EAGLEFLYING,
    EAGLEGOTHIT,
    EAGLESHOT,
    EAGLERAM,
    EAGLEDEAD,
    EAGLEHENSHIN,
    EAGLEHENSHINSHOT,
    COLLAPSIONBYEAGLE,
    EGGBIRD,
    EGGBIRDCOLLAPSION,
    DIAMOND,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    EVILBIRDCOLLAPSION
};