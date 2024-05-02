#include "../Header/Background.h"
#include "../Header/TextureManager.h"
#include "../Header/CommonFunction.h"

void Background::init() {
    ground = TextureManager::loadTexture(bg_ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        scrolling_layer[i] = 0;
        layer[i] = TextureManager::loadTexture(bg_layer[i]);
    }
}

void Background::scroll() {
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        scrolling_layer[i] -= LAYER_SPEED[i];
        if(scrolling_layer[i]<0) scrolling_layer[i] += SCREEN_WIDTH;
    }
}

void Background::update() {
    scroll();
}

void Background::render() {
    TextureManager::draw(ground);
    for(int i=0; i<TOTAL_BACKGROUND_LAYERS; i++) {
        TextureManager::draw(layer[i], scrolling_layer[i] - SCREEN_WIDTH, 0);
        TextureManager::draw(layer[i], scrolling_layer[i], 0);
    }    
}