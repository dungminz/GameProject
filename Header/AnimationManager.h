#pragma once

#include <iostream>
#include <vector>
#include <SDL_image.h>
#include "CommonFunction.h"

struct Animation {

    typeOfCharacror type;
    std::string img;
    SDL_Texture* texture;
    int flames;
    int w, h;
    std::vector<SDL_Rect> clips;
    
    void setInformation(typeOfCharacror _type, std::string _img, 
                                int _flames, int _w, int _h);
    void setInformation(typeOfCharacror _type, std::string _img, 
                int _flames, const int _clips[][4], int _w, int _h);                                
    void setTexture(SDL_Texture* _texture);
};
