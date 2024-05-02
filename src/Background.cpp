#include "../Header/Background.h"
#include "../header/TextureManager.h"

void Background::init() {
    ground = TextureManager::loadTexture(bg_ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        scrolling_layer[i] = width;
        layer[i] = TextureManager::loadTexture(bg_layer[i]);
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
    TextureManager::draw(ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        TextureManager::draw(layer[i], scrolling_layer[i] - width, 0);
        TextureManager::draw(layer[i], scrolling_layer[i], 0);
    }    
}