#include "../Header/Background.h"
#include "../header/DrawTexture.h"

void Background::init() {
    texture = DrawTexture::loadTexture("bg2.png");
    ground = DrawTexture::loadTexture(bg_ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        scrolling_layer[i] = width;
        layer[i] = DrawTexture::loadTexture(bg_layer[i]);
    }
    SDL_QueryTexture(ground, NULL, NULL, &width, &height);
}

void Background::scroll() {
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        scrolling_layer[i] -= LAYER_SPEED[i];
        if(scrolling_layer[i]<0) scrolling_layer[i] += width;
    }
}

void Background::update() {
    scroll();
}

void Background::render() {
    DrawTexture::draw(ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        DrawTexture::draw(layer[i], scrolling_layer[i] - width, 0);
        DrawTexture::draw(layer[i], scrolling_layer[i], 0);
    }    
}