#include "../Header/Background.h"
#include "../Header/CommonFunction.h"

Background::Background() {}

Background::Background(BackgroundManager* bgr) 
    : background_bgr(bgr) {}

void Background::init() {
    SDL_Texture* ground = TextureManager::loadTexture(background_bgr->ground_img);
    background_bgr->setGround(ground);
    for(int i=0; i<background_bgr->flames_layer; i++) {
        scrolling_layer[i] = 0;
        SDL_Texture* layer = TextureManager::loadTexture(background_bgr->layer_img[i]);
        background_bgr->setLayer(layer);
    }
}

void Background::scroll() {
    for(int i=0; i<background_bgr->flames_layer; i++) {
        scrolling_layer[i] -= LAYER_SPEED[i];
        if(scrolling_layer[i]<0) scrolling_layer[i] += SCREEN_WIDTH;
    }
}

void Background::update() {
    scroll();
}

void Background::render() {
    TextureManager::draw(background_bgr->ground_texture);
    for(int i=0; i<background_bgr->flames_layer; i++) {
        TextureManager::draw(background_bgr->layer_texture[i], scrolling_layer[i] - SCREEN_WIDTH, 0);
        TextureManager::draw(background_bgr->layer_texture[i], scrolling_layer[i], 0);
    }    
}