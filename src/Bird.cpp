#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::init() {
    bird_img = DrawTexture::loadTexture("eggbird.png");
    dino_img = DrawTexture::loadTexture("BlueTest.png");
    dino.init(dino_img, TOTAL_FLAME_DINO, DINO_CLIPS);
}

void Bird::update() {
    if(Game::leftPressed) mouse.turnLeft();
    if(Game::rightPressed) mouse.turnRight();
    if(Game::upPressed) mouse.turnUp();
    if(Game::downPressed) mouse.turnDown();
    dino.update();
}

void Bird::render() {
    int w, h;
    SDL_QueryTexture(bird_img, NULL, NULL, &w, &h);
    SDL_Rect src = {0, 0, w, h};
    SDL_Rect dest = {mouse.x, mouse.y, w/10, h/10}; 
    DrawTexture::draw(bird_img, &src, &dest);
    //DrawTexture::draw(dino_img, dino.getCurrentClip(), mouse.x, mouse.y);
}