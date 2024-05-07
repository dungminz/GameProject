#include "../Header/Bird.h"


MainBird::MainBird() {}

MainBird::MainBird(Animation* ani) : bird_ani(ani) {}

MainBird::~MainBird() {

    // if(bird_ani) delete bird_ani;
    // if(bird_mouse) delete bird_mouse;
    // if(bird_spr) delete bird_spr;
}

void MainBird::init() {

    SDL_Texture* bird = TextureManager::loadTexture(bird_ani->img);
    bird_ani->setTexture(bird);

    bird_spr = new Sprite();
    bird_spr->init(bird_ani);

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

    if(KeyPressed::mainbird_left) bird_mouse->turnLeft();
    if(KeyPressed::mainbird_right) bird_mouse->turnRight();
    if(KeyPressed::mainbird_up) bird_mouse->turnUp();
    if(KeyPressed::mainbird_down) bird_mouse->turnDown();
    bird_mouse->update();

    bird_spr->update();
}


void MainBird::render() { 

    TextureManager::draw(bird_ani->texture, bird_spr->getSrc(), bird_mouse->getDest());
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
    {}

SupportBird::~SupportBird() {

    // delete spbird_ani;
    // delete flying_ani;
    // delete gothit_ani;
    // delete shot_ani;
    // delete ram_ani;
    // delete dead_ani;
    // delete henshin_ani;
    // delete henshinshot_ani;
    delete spbird_mouse;
    delete spbird_spr;
}

void SupportBird::init() {

    SDL_Texture* spbird_flying = TextureManager::loadTexture(flying_ani->img);
    SDL_Texture* spbird_gothit = TextureManager::loadTexture(gothit_ani->img);
    SDL_Texture* spbird_shot = TextureManager::loadTexture(shot_ani->img);
    SDL_Texture* spbird_ram = TextureManager::loadTexture(ram_ani->img);
    SDL_Texture* spbird_dead = TextureManager::loadTexture(dead_ani->img);
    SDL_Texture* spbird_henshin = TextureManager::loadTexture(henshin_ani->img);
    SDL_Texture* spbird_henshinshot = TextureManager::loadTexture(henshinshot_ani->img);
    
    flying_ani->setTexture(spbird_flying);
    gothit_ani->setTexture(spbird_gothit);
    shot_ani->setTexture(spbird_shot);
    ram_ani->setTexture(spbird_ram);
    dead_ani->setTexture(spbird_dead);
    henshin_ani->setTexture(spbird_henshin);
    henshinshot_ani->setTexture(spbird_henshinshot);

    if(henshin_ani) spbird_ani = henshin_ani;
    
    spbird_spr = new Sprite();
    spbird_spr->init(spbird_ani);

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
    
    if(KeyPressed::supportbird_left) spbird_mouse->turnLeft();
    if(KeyPressed::supportbird_right) spbird_mouse->turnRight();
    if(KeyPressed::supportbird_up) spbird_mouse->turnUp();
    if(KeyPressed::supportbird_down) spbird_mouse->turnDown();
    spbird_mouse->update();

    spbird_spr->update();
}


void SupportBird::render() { 

    TextureManager::draw(spbird_ani->texture, spbird_spr->getSrc(), spbird_mouse->getDest());
}