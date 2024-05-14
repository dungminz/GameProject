#pragma once

// #include "Game.h"
#include "Sprite.h"


const std::string DIAMOND_IMG = "../Image/Animation/diamond.png";
const int FRAMES_DIAMOND = 8;
const int DIAMOND_W = 576;
const int DIAMOND_H = 512;
const int DIAMOND_REAL_W = DIAMOND_W/DIAMOND_SCALE;
const int DIAMOND_REAL_H = DIAMOND_H/DIAMOND_SCALE;
const int RANGE_FRAME_DIAMOND = 165+576;
const int CLIPS_DIAMOND[FRAMES_DIAMOND][4] = {
    {70+RANGE_FRAME_DIAMOND*0, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*1, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*2, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*3, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*4, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*5, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*6, 0, 576, 512},
    {70+RANGE_FRAME_DIAMOND*7, 0, 576, 512}
};

const std::string DIAMONDCOLLAPSION_IMG = "../Image/Animation/diamondcollapsion.png";
const int FRAMES_DIAMONDCOLLAPSION = 16;
const int DIAMONDCOLLAPSION_W = 180;
const int DIAMONDCOLLAPSION_H = 180;
const int DIAMONDCOLLAPSION_REAL_W = DIAMONDCOLLAPSION_W/DIAMONDCOLLAPSION_SCALE;
const int DIAMONDCOLLAPSION_REAL_H = DIAMONDCOLLAPSION_H/DIAMONDCOLLAPSION_SCALE;
const int RANGE_FRAME_DIAMONDCOLLAPSION = 180;
const int CLIPS_DIAMONDCOLLAPSION[FRAMES_DIAMONDCOLLAPSION][4] = {
    {RANGE_FRAME_DIAMONDCOLLAPSION*0, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*1, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*2, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*3, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*4, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*5, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*6, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*7, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*8, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*9, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*10, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*11, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*12, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*13, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*14, 0, 180, 180},
    {RANGE_FRAME_DIAMONDCOLLAPSION*15, 0, 180, 180}
};


const std::string ROCKET_IMG = "../Image/Animation/rocket.png";
const int FRAMES_ROCKET = 4;
const int ROCKET_W = 1075*2/3;
const int ROCKET_H = 350;
const int ROCKET_REAL_W = ROCKET_W/ROCKET_SCALE;
const int ROCKET_REAL_H = ROCKET_H/ROCKET_SCALE;
const int RANGE_FRAME_ROCKET = 1246;
const int CLIPS_ROCKET[FRAMES_ROCKET][4] = {
    {58, 65, 1075, 350},
    {1314, 65, 1075, 350},
    {2600, 65, 1075, 350},
    {3880, 65, 1075, 350},
};

const std::string ROCKETCOLLAPSION_IMG = "../Image/Animation/rocketcollapsion.png";
const int FRAMES_ROCKETCOLLAPSION = 18;
const int ROCKETCOLLAPSION_W = 180;
const int ROCKETCOLLAPSION_H = 180;
const int ROCKETCOLLAPSION_REAL_W = ROCKETCOLLAPSION_W/ROCKETCOLLAPSION_SCALE;
const int ROCKETCOLLAPSION_REAL_H = ROCKETCOLLAPSION_H/ROCKETCOLLAPSION_SCALE;
const int RANGE_FRAME_ROCKETCOLLAPSION = 180;
const int CLIPS_ROCKETCOLLAPSION[FRAMES_ROCKETCOLLAPSION][4] = {
    {RANGE_FRAME_ROCKETCOLLAPSION*0, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*1, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*2, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*3, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*4, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*5, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*6, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*7, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*8, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*9, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*10, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*11, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*12, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*13, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*14, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*15, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*16, 0, 180, 180},
    {RANGE_FRAME_ROCKETCOLLAPSION*17, 0, 180, 180},
};


const std::string EVILBIRD_IMG = "../Image/Animation/evilbird.png";
const int FRAMES_EVILBIRD = 8;
const int EVILBIRD_W = 342;
const int EVILBIRD_H = 280;
const int EVILBIRD_REAL_W = EVILBIRD_W/EVILBIRD_SCALE;
const int EVILBIRD_REAL_H = EVILBIRD_H/EVILBIRD_SCALE;
const int RANGE_FRAME_EVILBIRD = 601;
const int CLIPS_EVILBIRD[FRAMES_EVILBIRD][4] = {
    {120+RANGE_FRAME_EVILBIRD*0, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*1, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*2, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*3, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*4, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*5, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*6, 116, 342, 280},
    {120+RANGE_FRAME_EVILBIRD*7, 116, 342, 280}
};

const std::string MASKBIRD_IMG = "../Image/Animation/maskbird.png";
const int FRAMES_MASKBIRD = 8;
const int MASKBIRD_W = 305;
const int MASKBIRD_H = 283;
const int MASKBIRD_REAL_W = MASKBIRD_W/MASKBIRD_SCALE;
const int MASKBIRD_REAL_H = MASKBIRD_H/MASKBIRD_SCALE;
const int RANGE_FRAME_MASKBIRD = 780;
const int CLIPS_MASKBIRD[FRAMES_MASKBIRD][4] = {
    {238+RANGE_FRAME_MASKBIRD*0, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*1, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*2, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*3, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*4, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*5, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*6, 95, 305, 283},
    {238+RANGE_FRAME_MASKBIRD*7, 95, 305, 283},
};


struct Pos {
    int x, y, spr;
    int speed;
    
    Pos(int _x, int _y, int _spr) 
        : x(_x), y(_y), spr(_spr) {}
    Pos(int _x, int _y, int _spr, int _speed) 
        : x(_x), y(_y), spr(_spr), speed(_speed) {}
};

struct Enemy {

    class Sprite* enemy_spr;
    class Sprite* collapsion_spr;
    Animation* enemy_ani;
    Animation* collapsion_ani;
    int delay_spr = 0;
    std::vector<Pos> enemy_pos;
    std::vector<Pos> collapsion_pos;
    SDL_Rect* bird_dest;

    Enemy();
    Enemy(Animation* ani);
    Enemy(Animation* _enemy_ani, Animation* _collapsion_ani);
    ~Enemy();

    void init();
    void update(SDL_Rect* _bird_dest = nullptr);
    void render();
};

struct Rocket {

    class Sprite* enemy_spr;
    class Sprite* collapsion_spr;
    Animation* enemy_ani;
    Animation* collapsion_ani;
    int delay_spr = 0;
    std::vector<Pos> enemy_pos;
    std::vector<Pos> collapsion_pos;
    std::pair<int, int> bird_pos;

    Rocket();
    Rocket(Animation* ani);
    Rocket(Animation* _enemy_ani, Animation* _collapsion_ani);
    ~Rocket();

    void init();
    void update(std::pair<int, int> _bird);
    void render();
};