#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::init() {
    bird_img = DrawTexture::loadTexture("../Image/Animation/eggbird.png");
    bird.init(bird_img, FLAMES_EGG_BIRD, CLIPS_EGG_BIRD);
}

void Bird::update() {
    if(Game::leftPressed) mouse.turnLeft();
    if(Game::rightPressed) mouse.turnRight();
    if(Game::upPressed) mouse.turnUp();
    if(Game::downPressed) mouse.turnDown();
    bird.update();
}

void Bird::render() { 
    SDL_Rect dest = {mouse.x, mouse.y, 560/8, 420/8};
    DrawTexture::draw(bird_img, bird.getCurrentClip(), &dest);
}