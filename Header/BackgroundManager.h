#pragma once

#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "CommonFunction.h"

struct BackgroundManager {
    int type;
    std::string ground_img;
    std::vector<std::string> layer_img;
    int flames_layer;
    SDL_Texture* ground_texture;
    std::vector<SDL_Texture*> layer_texture;

    void setInformation(typeOfBackground _type, 
            std::string _ground_img, int _flames_layer);

    void setInformation(typeOfBackground _type, 
                std::string _ground_img, int _flames_layer, 
                                    const std::string _clips[]);

    void setGround(SDL_Texture* _ground_texture);

    void setLayer(SDL_Texture* _layer_texture);
};