#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"

void Enemy::init() {
    enemy_img = TextureManager::loadTexture(DIAMOND_IMG);
    enemy_spr.init(enemy_img, FLAMES_DIAMOND, CLIPS_DIAMOND);

    enemycollaption_img = TextureManager::loadTexture(DIAMONDCOLLAPSION_IMG);
    enemycollaption_spr.init(enemycollaption_img, FLAMES_DIAMONDCOLLAPSION, CLIPS_DIAMONDCOLLAPSION);
}

void Enemy::update() {
    delay = ++delay%SPRITE_DELAY;

    enemycollaption_spr.update();
}
void Enemy::update(Pos &pos, int typeOfEnemy) {
    if(typeOfEnemy == DIAMOND) {
        if(!delay) {
            pos.spr = ++pos.spr%FLAMES_DIAMOND;
        }
        pos.x-=pos.speed;
    }
    if(typeOfEnemy == DIAMONDCOLLAPSION) {
        if(!delay) {
            pos.spr++;
        }
    }
}


void Enemy::render(int x, int y, int spr, int typeOfEnemy) {

    if(typeOfEnemy == DIAMOND) {
        SDL_Rect src = enemy_spr.clips[spr];
        SDL_Rect dest = {x, y, DIAMOND_REAL_W, DIAMOND_REAL_H};
        TextureManager::draw(enemy_img, &src, &dest);
    }

    if(typeOfEnemy == DIAMONDCOLLAPSION) {
        SDL_Rect src = enemycollaption_spr.clips[spr];
        SDL_Rect dest = {x, y, DIAMONDCOLLAPSION_REAL_W, DIAMONDCOLLAPSION_REAL_H};
        TextureManager::draw(enemycollaption_img, &src, &dest);
    }
}