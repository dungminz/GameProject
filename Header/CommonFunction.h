#pragma once



const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#define WINDOW_TITLE "~New Game~"

const int ICON_SIZE = 100;
const double ICON_R = ICON_SIZE/2;

const int INITIAL_DISTANCE = 3;
const int MAX_LAYER = 6;
const double LAYER_SPEED[MAX_LAYER] = {
    0.3, 0.5, 0.7, 0.9, 1.1, 1.3
};

const double EGGBIRD_SCALE = 7;
const double UNICORNBIRD_SCALE = 7;
const double ROCKET_SCALE = 5;
const double COLLAPSION_BY_EAGLE_SCALE = 1;
const double DIAMOND_SCALE = 10;
const double DIAMONDCOLLAPSION_SCALE = 2.5;
const double EVILBIRD_SCALE = 3.75;

const int MAIN_BIRD_ORIGIN_POS_X = 100;
const int MAIN_BIRD_ORIGIN_POS_Y = SCREEN_HEIGHT/2;

const int SUPPORT_BIRT_ORIGIN_POS_X = 200;
const int SUPPORT_BIRT_ORIGIN_POS_Y = SCREEN_HEIGHT/2;

const int SPRITE_DELAY = 5;
const int STEPS_MOVE_BIRD = 4;
const int DISTANCE_TO_SCREEN = 10;

const int ENEMY_MIN_SPEED = 1;
const int ENEMY_MAX_SPEED = 5;

namespace KeyPressed {
    extern bool mainbird_left;
    extern bool mainbird_right;
    extern bool mainbird_up;
    extern bool mainbird_down;
    extern bool supportbird_left;
    extern bool supportbird_right;
    extern bool supportbird_up;
    extern bool supportbird_down;
}

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
    UNICORNBIRD,
    DIAMOND,
    ROCKET,
    DIAMONDCOLLAPSION,
    EVILBIRD,
    EVILBIRDCOLLAPSION
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