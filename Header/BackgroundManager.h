#pragma once

#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "CommonFunction.h"

struct BackgroundManager {
    int type;
    std::string ground_img;
    std::string *layer_img;
    int frames_layer;
    SDL_Texture* ground_texture;
    SDL_Texture** layer_texture;

    BackgroundManager();
    BackgroundManager(typeOfBackground _type, 
                std::string _ground_img, int _frames_layer, 
                                const std::string _clips[]);
    ~BackgroundManager();

    void setTexture();
};