#pragma once

#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "CommonFunction.h"

struct Animation {

    typeOfCharacror type;
    std::string img;
    SDL_Texture* texture;
    int frames;
    int w, h;
    SDL_Rect* clips;

    Animation();
    Animation(typeOfCharacror _type, std::string _img, 
                int _frames, const int _clips[][4], int _w, int _h);
    ~Animation();
    
    void setTexture();
};
