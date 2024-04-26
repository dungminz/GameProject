#pragma once

#include "CommonFunction.h"
#include "Game.h"

const int INITIAL_DISTANCE = 3;

const int TOTAL_BACKGROUND_LAYERS = 6;

const double LAYER_SPEED[TOTAL_BACKGROUND_LAYERS] = {
    0.5, 0.75, 1, 1.25, 1.5, 1.75
};

struct Background {

    string bg_ground;
    string bg_layer[TOTAL_BACKGROUND_LAYERS];

    Background() {
        bg_ground = "../Image/background/bg0.png";
        bg_layer[0] = "../Image/background/0.png";
        bg_layer[1] = "../Image/background/1.png";
        bg_layer[2] = "../Image/background/2.png";
        bg_layer[3] = "../Image/background/3.png";
        bg_layer[4] = "../Image/background/4.png";
        bg_layer[5] = "../Image/background/5.png";
    };
    //~Background() {};
    
    SDL_Texture *texture;
    SDL_Texture *ground;
    SDL_Texture *layer[TOTAL_BACKGROUND_LAYERS];
    int width, height;
    double scrolling_layer[TOTAL_BACKGROUND_LAYERS];
    
    void init();
    void scroll();
    void update();
    void render();
};