#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::init() {
    bird_img = TextureManager::loadTexture("bird.png");
}

void Bird::update() {
    if(Game::leftPressed) mouse.turnLeft();
    if(Game::rightPressed) mouse.turnRight();
    if(Game::upPressed) mouse.turnUp();
    if(Game::downPressed) mouse.turnDown();
}

void Bird::render() {
    TextureManager::draw(bird_img, mouse.x, mouse.y);
}