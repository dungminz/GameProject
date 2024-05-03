#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"

Enemy::Enemy() {}
Enemy::Enemy(Animation* ani) : enemy_ani(ani) {}


void Enemy::init() {

    // enemy_ani.setInformation()
    enemy_img = TextureManager::loadTexture(enemy_ani->img);
    enemy_ani->setTexture(enemy_img);
    enemy_spr.init(enemy_ani->texture, FLAMES_DIAMOND, CLIPS_DIAMOND);

    enemycollaption_img = TextureManager::loadTexture(DIAMONDCOLLAPSION_IMG);
    enemycollaption_spr.init(enemycollaption_img, FLAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION);
}


void Enemy::update() {

    delay_spr = ++delay_spr%SPRITE_DELAY;
}

void Enemy::updateEnemy(Pos &pos) {

    if(!delay_spr) pos.spr = ++pos.spr%FLAMES_DIAMOND;
    pos.x-=pos.speed;
}

void Enemy::updateCollapsion(Pos &pos) { 

    if(!delay_spr) pos.spr++;
}


void Enemy::renderEnemy(Pos &pos) {

        SDL_Rect src = enemy_spr.clips[pos.spr];
        SDL_Rect dest = {pos.x, pos.y, DIAMOND_REAL_W, DIAMOND_REAL_H};
        TextureManager::draw(enemy_ani->texture, &src, &dest);
}

void Enemy::renderCollapsion(Pos &pos) {

        SDL_Rect src = enemycollaption_spr.clips[pos.spr];
        SDL_Rect dest = {pos.x, pos.y, DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H};
        TextureManager::draw(enemycollaption_img, &src, &dest);
}