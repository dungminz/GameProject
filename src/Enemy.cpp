#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"

void Enemy::init() {
    
    enemy_img = TextureManager::loadTexture(DIAMOND_IMG);
    enemy_spr.init(enemy_img, FLAMES_DIAMOND, CLIPS_DIAMOND);
}

void Enemy::update() {
    delay = ++delay%SPRITE_DELAY;
}
void Enemy::update(Pos &pos) {
    if(!delay) {
        pos.spr = ++pos.spr%FLAMES_DIAMOND;
    }
    pos.x-=pos.speed;
}

void Enemy::render(int x, int y, int spr) {
    SDL_Rect dest = {x, y, DIAMOND_REAL_W, DIAMOND_REAL_H};
    SDL_Rect src = enemy_spr.clips[spr];
    TextureManager::draw(enemy_img, &src, &dest);
}