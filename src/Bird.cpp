#include "../Header/Bird.h"


MainBird::MainBird() :
    bird_mouse(MAIN_BIRD_ORIGIN_POS_X, MAIN_BIRD_ORIGIN_POS_Y, 
                            EGGBIRD_REAL_W, EGGBIRD_REAL_H) {}

MainBird::MainBird(Animation* ani) :
    bird_ani(ani),
    bird_mouse(MAIN_BIRD_ORIGIN_POS_X, MAIN_BIRD_ORIGIN_POS_Y, 
                                bird_ani->w, bird_ani->h) {}


void MainBird::init() {

    bird_img = TextureManager::loadTexture(bird_ani->img);
    bird_ani->setTexture(bird_img);
    bird_spr.init(bird_ani);
}


void MainBird::update() {

    bird_mouse.update();
    bird_spr.update();
}


void MainBird::render() { 

    TextureManager::draw(bird_img, bird_spr.getSrc(), bird_mouse.getDest());
}