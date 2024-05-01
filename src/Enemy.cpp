#include "../Header/Enemy.h"

void Enemy::init() {
    diamond_img = DrawTexture::loadTexture("../Image/Animation/diamond.png");
    diamond_spr.init(diamond_img, FLAMES_DIAMOND, CLIPS_DIAMOND);
    diamond_dest = {1280/2, 720/2, 576/8, 512/8};
}

void Enemy::update() {
    diamond_spr.update();
 }

void Enemy::render() {
    DrawTexture::draw(diamond_img, diamond_spr.getSrc(), &diamond_dest);
}
