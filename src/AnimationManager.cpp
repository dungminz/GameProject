#include "../Header/AnimationManager.h"


Animation::Animation() {}

Animation::~Animation() {
    // if(texture) SDL_DestroyTexture(texture);
    // if(clips) delete[] clips;
}

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
    clips = new SDL_Rect[flames];
    for(int i=0; i<flames; i++) {
        SDL_Rect clip;
        clip.x = _clips[i][0];
        clip.y = _clips[i][1];
        clip.w = _clips[i][2];
        clip.h = _clips[i][3];
        clips[i] = clip;
    }
}


void Animation::setTexture(SDL_Texture* _texture) {

    texture = _texture;
}