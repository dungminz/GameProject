#include "../Header/Sprite.h"
#include "../Header/CommonFunction.h"


Sprite::Sprite () {}

Sprite::~Sprite() {}


void Sprite::init(Animation* ani) {

    texture = ani->texture;
    frames = ani->frames;
    clips = ani->clips;
}


void Sprite::tick() {

    currentFrame = ++currentFrame%frames;
}


void Sprite::update() {

    delay = ++delay%SPRITE_DELAY;
    if(!delay) tick();
}


SDL_Rect* Sprite::getSrc() {
    
    return &clips[currentFrame];
}