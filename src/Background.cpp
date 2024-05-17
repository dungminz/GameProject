#include "../Header/Background.h"
#include "../Header/CommonFunction.h"

Background::Background() {}

Background::Background(BackgroundManager* bgr) 
    : background_bgr(bgr) {}

Background::~Background() {
    delete scrolling_layer;
}


void Background::init() {

    scrolling_layer = new float[background_bgr->frames_layer];
    for(int i=0; i<background_bgr->frames_layer; i++) {

        scrolling_layer[i] = 0;
    }
}


void Background::scroll() {

    for(int i=0; i<background_bgr->frames_layer; i++) {

        scrolling_layer[i] -= LAYER_SPEED[i];
        if(scrolling_layer[i]<0) scrolling_layer[i] += SCREEN_WIDTH;
    }
}


void Background::update() {

    scroll();
}


void Background::render() {

    TextureManager::draw(background_bgr->ground_texture);
    for(int i=0; i<background_bgr->frames_layer; i++) {

        TextureManager::drawBackground(background_bgr->layer_texture[i], scrolling_layer[i] - SCREEN_WIDTH, 0);
        TextureManager::drawBackground(background_bgr->layer_texture[i], scrolling_layer[i], 0);
    }    
}