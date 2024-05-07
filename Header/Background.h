#pragma once

#include "Game.h"


const int FLAMES_LAYER_NIGHT = 6;
const std::string NIGHT_BG = "../Image/Background/bg2.png";
const std::string NIGHT_LAYER[FLAMES_LAYER_NIGHT] = {
    "../Image/Background/21.png",
    "../Image/Background/22.png",
    "../Image/Background/23.png",
    "../Image/Background/24.png",
    "../Image/Background/25.png",
    "../Image/Background/26.png",
};

const int FLAMES_LAYER_DAY = 6;
const std::string DAY_BG = "../Image/Background/bg1.png";
const std::string DAY_LAYER[FLAMES_LAYER_DAY] = {
    "../Image/Background/11.png",
    "../Image/Background/12.png",
    "../Image/Background/13.png",
    "../Image/Background/14.png",
    "../Image/Background/15.png",
    "../Image/Background/16.png",
};


struct Background {

    BackgroundManager* background_bgr;
    double *scrolling_layer;

    Background();
    Background(BackgroundManager* bgr);
    ~Background() ;
    
    void init();
    void scroll();
    void update();
    void render();
};