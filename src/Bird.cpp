#include "../Header/Bird.h"


MainBird::MainBird() {}

MainBird::MainBird(Animation* ani) : bird_ani(ani) {}

MainBird::~MainBird() {

    if(bird_mouse) delete bird_mouse;
    if(bird_spr) delete bird_spr;
}

void MainBird::init() {

    bird_spr = new Sprite(bird_ani);
    // bird_spr->init(bird_ani);

    bird_mouse = new Mouse();
    bird_mouse->init(MAIN_BIRD_ORIGIN_POS_X, MAIN_BIRD_ORIGIN_POS_Y, 
                                bird_ani->w, bird_ani->h);
}


void MainBird::handle_events(SDL_Event& event) {

    switch(event.type) {

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_a: KeyPressed::mainbird_left=true;  KeyPressed::mainbird_right=false; break;
                case SDLK_d: KeyPressed::mainbird_right=true; KeyPressed::mainbird_left=false;  break;
                case SDLK_w: KeyPressed::mainbird_up=true;    KeyPressed::mainbird_down=false;  break;
                case SDLK_s: KeyPressed::mainbird_down=true;  KeyPressed::mainbird_up=false;    break;
                default: break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_a: KeyPressed::mainbird_left=false;  break;
                case SDLK_d: KeyPressed::mainbird_right=false; break;
                case SDLK_w: KeyPressed::mainbird_up=false;    break;
                case SDLK_s: KeyPressed::mainbird_down=false;  break;
                default: break;
            }
            break;

        default: break;
    }
}


void MainBird::update() {

    bird_mouse->updateMainBird();

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

    delete spbird_mouse;
    delete spbird_spr;
}

void SupportBird::init() {

    if(spbird_ani) spbird_ani = flying_ani;
    
    spbird_spr = new Sprite(spbird_ani);
    // spbird_spr->init(spbird_ani);

    spbird_mouse = new Mouse();
    spbird_mouse->init(SUPPORT_BIRT_ORIGIN_POS_X, SUPPORT_BIRT_ORIGIN_POS_Y, 
                                spbird_ani->w, spbird_ani->h);
}


void SupportBird::handle_events(SDL_Event& event) {

    switch(event.type) {

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  KeyPressed::supportbird_left=true;  KeyPressed::supportbird_right=false; break;
                case SDLK_RIGHT: KeyPressed::supportbird_right=true; KeyPressed::supportbird_left=false;  break;
                case SDLK_UP:    KeyPressed::supportbird_up=true;    KeyPressed::supportbird_down=false;  break;
                case SDLK_DOWN:  KeyPressed::supportbird_down=true;  KeyPressed::supportbird_up=false;    break;
                default: break;
            }
            break;

        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:  KeyPressed::supportbird_left=false;  break;
                case SDLK_RIGHT: KeyPressed::supportbird_right=false; break;
                case SDLK_UP:    KeyPressed::supportbird_up=false;    break;
                case SDLK_DOWN:  KeyPressed::supportbird_down=false;  break;
                default: break;
            }
            break;

        default: break;
    }
}


void SupportBird::update() {
    
    spbird_mouse->updateSupportBird();
    spbird_spr->update();
}


void SupportBird::render() { 

    TextureManager::drawAngle(spbird_ani->texture, spbird_spr->getSrc(), spbird_mouse->getDest(), spbird_mouse->angle);
}


void SupportBird::clean() {
    delete spbird_spr;
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

    spbird_ani = ani;
    delete spbird_spr;
    spbird_spr = new Sprite(spbird_ani);
}