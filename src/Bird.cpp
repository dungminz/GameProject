#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::init() {
    bird_img = DrawTexture::loadTexture("eggbird.png");
}

void Bird::update() {
    if(Game::leftPressed) mouse.turnLeft();
    if(Game::rightPressed) mouse.turnRight();
    if(Game::upPressed) mouse.turnUp();
    if(Game::downPressed) mouse.turnDown();
}

void Bird::render() {
    int w, h;
    SDL_QueryTexture(bird_img, NULL, NULL, &w, &h);
    SDL_Rect src = {0, 0, w/8, h};
    // std::cout<<(double)w/8<<' '<<(double)h<<'\n';
    DrawTexture::draw(bird_img, &src, mouse.x, mouse.y);
}