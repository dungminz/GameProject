#include "../Header/Bird.h"



MainBird::MainBird() {}

MainBird::MainBird(Animation* ani) : bird_ani(ani) {}

MainBird::~MainBird() {

    if(bird_mouse) delete bird_mouse;
    if(bird_spr) delete bird_spr;
}


void MainBird::init() {

    bird_mouse = new Mouse({MAIN_BIRD_ORIGIN_POS_X, MAIN_BIRD_ORIGIN_POS_Y, 
                                bird_ani->w, bird_ani->h});

    bird_spr = new Sprite(bird_ani);
}

void MainBird::update() {

    bird_mouse->update();
    bird_spr->update();
}

void MainBird::render() { 

    TextureManager::drawAngle(bird_ani->texture, bird_spr->getSrc(), bird_mouse->getDest(), bird_mouse->angle);
}




SupportBird::SupportBird() {}

SupportBird::SupportBird(Animation* _flying_ani, 
                Animation* _gothit_ani, Animation* _shot_ani, 
                Animation* _ram_ani, Animation* _dead_ani, 
                Animation* _henshin_ani, Animation* _henshinshot_ani)
    : spbird_ani(_flying_ani), flying_ani(_flying_ani), 
    gothit_ani(_gothit_ani), shot_ani(_shot_ani),
    ram_ani(_ram_ani), dead_ani(_dead_ani),
    henshin_ani(_henshin_ani), henshinshot_ani(_henshinshot_ani)
{
    health = MAX_BIRD_HEALTH;
    alive = true;    
}

SupportBird::~SupportBird() {

    if(spbird_mouse) delete spbird_mouse;
    if(spbird_spr) delete spbird_spr;
}


void SupportBird::init() {

    if(spbird_ani) spbird_ani = flying_ani;
    
    spbird_spr = new Sprite(spbird_ani);

    spbird_mouse = new Mouse({SUPPORT_BIRT_ORIGIN_POS_X, SUPPORT_BIRT_ORIGIN_POS_Y, 
                                spbird_ani->w, spbird_ani->h});
}

void SupportBird::update() {
    
    spbird_mouse->update();
    spbird_spr->update();
}

void SupportBird::render() { 

    TextureManager::drawAngle(spbird_ani->texture, spbird_spr->getSrc(), spbird_mouse->getDest(), spbird_mouse->angle);
}

void SupportBird::free() {

    if(spbird_spr) delete spbird_spr;
}


void SupportBird::check_sp(int _add) {

    health+=_add;
    if(health>MAX_BIRD_HEALTH) health = MAX_BIRD_HEALTH;
    if(health<=0) {
        alive = false;
        health = 0;
    }
    if(alive==false) setBird(dead_ani);
}

void SupportBird::setBird(Animation* ani) {
    
    free();

    spbird_ani = ani;
    spbird_spr = new Sprite(spbird_ani);
}