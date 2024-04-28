#include <iostream>
#include "../Header/Bird.h"

Bird::Bird() {}

void Bird::init() {
    bird_img = DrawTexture::loadTexture("bird.png");
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
    // DrawTexture::draw(bird_img, mouse.x, mouse.y);
    DrawTexture::draw(dino_img, dino.getCurrentClip(), mouse.x, mouse.y);
}