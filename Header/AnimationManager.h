#pragma once

#include <iostream>
#include <SDL_image.h>
#include "CommonFunction.h"

struct Animation {

    typeOfCharacror type;
    std::string img;
    SDL_Texture* texture;
    int flames;
    int w, h;
    int clips[][4];
    
    void setInformation(typeOfCharacror _type, std::string _img, 
                                int _flames, int _w, int _h);
    // void setInformation(typeOfCharacror _type, SDL_Texture *_texture, 
    //                             int _flames, int _w, int _h);
};

