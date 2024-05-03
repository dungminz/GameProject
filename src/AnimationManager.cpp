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

void Animation::setInformation(typeOfCharacror _type, std::string _img, 
                int _flames, const int _clips[][4], int _w, int _h)
{
    type = _type;
    img = _img;
    flames = _flames;
    w = _w; 
    h = _h;
    for(int i=0; i<flames; i++) {
        SDL_Rect clip;
        clip.x = _clips[i][0];
        clip.y = _clips[i][1];
        clip.w = _clips[i][2];
        clip.h = _clips[i][3];
        clips.push_back(clip);
    }
}

void Animation::setTexture(SDL_Texture* _texture) {
    texture = _texture;
}