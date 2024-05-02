#include "../Header/Enemy.h"

void Enemy::init() {
    enemy_img = DrawTexture::loadTexture("../Image/Animation/diamond.png");
    enemy_spr.init(enemy_img, FLAMES_DIAMOND, CLIPS_DIAMOND);
    // enemy_dest = {1280/2, 720/2, 576/8, 512/8};
}

void Enemy::update() {
    delay = ++delay%SPRITE_DELAY;
}
void Enemy::update(int &pos_spr) {
    
    if(!delay) {
        pos_spr = ++pos_spr%FLAMES_DIAMOND;
    }
}

void Enemy::render(int x, int y, int spr) {
    SDL_Rect dest = {x, y, DIAMOND_REAL_W, DIAMOND_REAL_H};
    std::cerr<<x<<' '<<y<<' '<<'\n';
    SDL_Rect src = enemy_spr.clips[spr];
    DrawTexture::draw(enemy_img, &src, &dest);
}