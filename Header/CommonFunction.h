#pragma once

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~Flapy Couple~"

const int FPS = 60;
const float FRAME_MAX_DELAY = 1000.f/FPS;

const int FPS_ANIMATION = 12;
const float FRAME_MAX_DELAY_ANIMATION = 1000.f/FPS_ANIMATION;

const int FPS_MOVE = 12;
const float FRAME_MAX_DELAY_MOVE = 1000.f/FPS_MOVE;

extern int highscore;

const int ICON_SIZE = 100;
const float ICON_R = ICON_SIZE/2;

const int INITIAL_DISTANCE = 3;
const int MAX_LAYER = 6;
const float LAYER_SPEED[MAX_LAYER] = {
    0.3, 0.5, 0.7, 0.9, 1.1, 1.3
};

const int MAPS = 2;
const int WAVE_END = 3;
const int WAVE_BONUS = WAVE_END + 1;

const float EGGBIRD_SCALE = 7;
const float UNICORNBIRD_SCALE = 7;
const float COLLAPSION_BY_EAGLE_SCALE = 1;
const float COLLAPSION_BY_CHICKEN_SCALE = 1;
const float DIAMOND_SCALE = 10;
const float DIAMONDCOLLAPSION_SCALE = 1;
const float ROCKET_SCALE = 5;
const float ROCKETCOLLAPSION_SCALE = 1;
const float EVILBIRD_SCALE = 3.75;
const float MASKBIRD_SCALE = 3.75;

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
const SDL_Color red = {255, 0, 0, 255};

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
    UNICORNBIRD,
    DIAMOND,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    MASKBIRD,
    ROCKET,
    ROCKETCOLLAPSION,
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

const int SPEED_ORIGIN_DIAMOND = 100;
const int SPEED_ORIGIN_ENEMY = 100;
const int SPEED_ORIGIN_ROCKET = 300;
const int ROCKET_SPEED_TO_BIRD = 50;
const float SPEED_SCALE = 0.5;

const int TIME_EACH_WAVE = 15000;
const int TIME_EACH_TURN = 2000;
const int TIME_TEXT_WAVE_DRAW = 2000;
const int TIME_GOT_HIT = 500;

const int TURNS_EACH_WAVE = 10;
const int DIAMOND_EACH_TURN_ORIGIN = 2;
const int ENEMY_BIRD_EACH_TURN_ORIGIN = 1;

const int MAX_BIRD_HEALTH = 150;
const int BIRD_HEALTH_ORIGIN = 100;
const int BIRD_HEALTH_BY_DIAMOND = 5;
const int BIRD_HEALTH_BY_ENEMYBIRD = -30;
const int BIRD_HEALTH_BY_ROCKET = -50;
const int TIME_CREATE_ENEMY = 5000;