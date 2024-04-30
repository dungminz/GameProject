#include "../Header/Enemy.h"

void Enemy::init() {
    diamond_img = DrawTexture::loadTexture("../Image/Animation/diamond.png");
    diamond.init(diamond_img, FLAMES_DIAMOND, CLIPS_DIAMOND);
}

void Enemy::update() {
    diamond.update();
 }

void Enemy::render() {
    SDL_Rect dest = {1280/2, 720/2, 576/8, 512/8};
    DrawTexture::draw(diamond_img, diamond.getCurrentClip(), &dest);
}
