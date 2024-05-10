#include "../Header/AnimationManager.h"
#include "../Header/Graphics.h"


Animation::Animation() {}

Animation::Animation(typeOfCharacror _type, std::string _img, 
                int _frames, const int _clips[][4], int _w, int _h)
{
    type = _type;
    img = _img;
    frames = _frames;
    w = _w; 
    h = _h;
    clips = new SDL_Rect[frames];
    for(int i=0; i<frames; i++) {
        SDL_Rect clip;
        clip.x = _clips[i][0];
        clip.y = _clips[i][1];
        clip.w = _clips[i][2];
        clip.h = _clips[i][3];
        clips[i] = clip;
    }
    setTexture();
}

Animation::~Animation() {

    if(texture) SDL_DestroyTexture(texture);
    if(clips) delete[] clips;
}


void Animation::setTexture() {
    
    texture = TextureManager::loadTexture(img);
}