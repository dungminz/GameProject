#include "../Header/AnimationManager.h"

void Animation::setInformation(typeOfCharacror _type, std::string _img, 
                                    int _flames, int _w, int _h)
{
    type = _type;
    img = _img;
    flames = _flames;
    w = _w; 
    h = _h;
}

// void Animation::setInformation(typeOfCharacror _type, SDL_Texture *_texture, 
//                                     int _flames, int _w, int _h)
// {
//     type = _type;
//     texture = _texture;
//     flames = _flames;
//     w = _w; 
//     h = _h;
// }
