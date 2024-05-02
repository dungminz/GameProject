#include <iostream>
#include "../Header/Bird.h"


Bird::Bird()
    : bird_mouse(MAIN_BIRD_ORIGIN_POS_X, MAIN_BIRD_ORIGIN_POS_Y, 
            EGG_BIRD_REAL_W, EGG_BIRD_REAL_H) {}

void Bird::init() {
    bird_img = TextureManager::loadTexture(EGG_BIRD_IMG);
    bird_spr.init(bird_img, FLAMES_EGG_BIRD, CLIPS_EGG_BIRD);
}

void Bird::update() {
    bird_mouse.update();
    bird_spr.update();
}

void Bird::render() { 
    TextureManager::draw(bird_img, bird_spr.getSrc(), bird_mouse.getDest());
}