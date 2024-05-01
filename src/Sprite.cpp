#include "../Header/Sprite.h"

void Sprite::init(SDL_Texture *_texture, const int _flames, const int _clips[][4]) {
    texture = _texture;
    flames = _flames;
    for(int i=0; i<flames; i++) {
        SDL_Rect clip;
        clip.x = _clips[i][0];
        clip.y = _clips[i][1];
        clip.w = _clips[i][2];
        clip.h = _clips[i][3];
        clips.push_back(clip);
    }
}

void Sprite::tick() {
    currentFlame = ++currentFlame%flames;
}

void Sprite::update() {
    ticks = ++ticks%5;
    if(!ticks) tick();
}

SDL_Rect* Sprite::getSrc() {
    return &clips[currentFlame];
}