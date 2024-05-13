#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~Flapy Couple~"

const int FPS = 60;
const float FRAME_MAX_DELAY = 1000.f/FPS;

extern int highscore;

const int ICON_SIZE = 100;
const double ICON_R = ICON_SIZE/2;

const int INITIAL_DISTANCE = 3;
const int MAX_LAYER = 6;
const double LAYER_SPEED[MAX_LAYER] = {
    0.3, 0.5, 0.7, 0.9, 1.1, 1.3
};

const int MAPS = 2;

const double EGGBIRD_SCALE = 7;
const double UNICORNBIRD_SCALE = 7;
const double ROCKET_SCALE = 5;
const double COLLAPSION_BY_EAGLE_SCALE = 1;
const double COLLAPSION_BY_CHICKEN_SCALE = 1;
const double DIAMOND_SCALE = 10;
const double DIAMONDCOLLAPSION_SCALE = 2.5;
const double EVILBIRD_SCALE = 3.75;
const double MASKBIRD_SCALE = 3.75;

const int MAIN_BIRD_ORIGIN_POS_X = SCREEN_WIDTH/10;
const int MAIN_BIRD_ORIGIN_POS_Y = SCREEN_HEIGHT/2;

const int SUPPORT_BIRT_ORIGIN_POS_X = SCREEN_WIDTH/10*2;
const int SUPPORT_BIRT_ORIGIN_POS_Y = SCREEN_HEIGHT/2;

const int SPRITE_DELAY = 5;
const int STEPS_MOVE_BIRD = 4;
const int DISTANCE_TO_SCREEN = 3;
const int MAX_ANGLE = 30;
const int ANGLE_STEP = 4;

const SDL_Color white = {255, 255, 255, 255};
const SDL_Color black = {0, 0, 0, 0};
const SDL_Color yellow = {255, 255, 0, 255};

// namespace KeyPressed {
//     extern bool mainbird_left;
//     extern bool mainbird_right;
//     extern bool mainbird_up;
//     extern bool mainbird_down;
//     extern bool supportbird_left;
//     extern bool supportbird_right;
//     extern bool supportbird_up;
//     extern bool supportbird_down;
// }

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

    CHICKEN,
    CHICKENCOLLAPSION,
    CHICKENFLYING,
    CHICKENGOTHIT,
    CHICKENSHOT,
    CHICKENRAM,
    CHICKENDEAD,
    CHICKENHENSHIN,
    CHICKENHENSHINSHOT,
    COLLAPSIONBYCHICKEN,

    EGGBIRD,
    EGGBIRDCOLLAPSION,
    UNICORNBIRD,
    DIAMOND,
    ROCKET,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    MASKBIRD,
};

enum typeOfBackground {
    DAY,
    NIGHT
};

enum class GameState {
    Begin,
    ChooseMainBird,
    ChooseSupportBird,
    Play,
    End,
    Quit,
    Null
};

const int ENEMY_MIN_SPEED = 2;
const int ENEMY_MAX_SPEED = ENEMY_MIN_SPEED+3;

const int TIME_EACH_WAVE = 15000;
const int TIME_EACH_TURN = 2000;
const int TIME_TEXT_WAVE_DRAW = 2000;
const int TURNS_EACH_WAVE = 5;
const int DIAMOND_EACH_TURN = 3;
const int ENEMY_BIRD_EACH_TURN = 2;

const int MAX_BIRD_HEALTH = 100;
const int BIRD_HEALTH_BY_DIAMOND = 5;
const int BIRD_HEALTH_BY_ENEMYBIRD = -50;
const int BIRD_HEALTH_BY_ROCKET = -50;
const int TIME_CREATE_ENEMY = 5000;