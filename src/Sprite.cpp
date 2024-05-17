#include "../Header/Sprite.h"
#include "../Header/CommonFunction.h"


Sprite::Sprite () {}

Sprite::Sprite(Animation* ani) {
    
    texture = ani->texture;
    numFrames = ani->frames;
    clips = ani->clips;
}

Sprite::~Sprite() {}


void Sprite::init() {

    time_sprite.start();
}

void Sprite::update() {

    float dT = time_sprite.getTicks();
    int frames_to_update = dT/FRAME_MAX_DELAY_ANIMATION;

    if(frames_to_update>0) {
        currentFrame+=frames_to_update;
        currentFrame%=numFrames;
        time_sprite.reset();
    }
}


SDL_Rect* Sprite::getSrc() {
    
    return &clips[currentFrame];
}