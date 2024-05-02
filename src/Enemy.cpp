#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"

void Enemy::init() {
    
    enemy_img = DrawTexture::loadTexture(DIAMOND_IMG);
    enemy_spr.init(enemy_img, FLAMES_DIAMOND, CLIPS_DIAMOND);
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
    SDL_Rect src = enemy_spr.clips[spr];
    DrawTexture::draw(enemy_img, &src, &dest);
}