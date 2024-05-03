#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"


Enemy::Enemy() {}

Enemy::Enemy(Animation* ani) : enemy_ani(ani) {}

Enemy::Enemy(Animation* _enemy_ani, Animation* _collapsion_ani)
    : enemy_ani(_enemy_ani), collapsion_ani(_collapsion_ani) {}


void Enemy::init() {

    SDL_Texture* enemy_img = TextureManager::loadTexture(enemy_ani->img);
    enemy_ani->setTexture(enemy_img);
    enemy_spr.init(enemy_ani);

    SDL_Texture* collapsion_img = TextureManager::loadTexture(collapsion_ani->img);
    collapsion_ani->setTexture(collapsion_img);
    collapsion_spr.init(collapsion_ani);
}


void Enemy::update() {

    delay_spr = ++delay_spr%SPRITE_DELAY;
}

void Enemy::updateEnemy(Pos &pos) {

    if(!delay_spr) pos.spr = ++pos.spr%SPRITE_DELAY;
    pos.x-=pos.speed;
}

void Enemy::updateCollapsion(Pos &pos) { 

    if(!delay_spr) pos.spr++;
}


void Enemy::renderEnemy(Pos &pos) {

    SDL_Rect src = enemy_spr.clips[pos.spr];
    SDL_Rect dest = {pos.x, pos.y, enemy_ani->w, enemy_ani->h};
    TextureManager::draw(enemy_ani->texture, &src, &dest);
}

void Enemy::renderCollapsion(Pos &pos) {

    SDL_Rect src = collapsion_spr.clips[pos.spr];
    SDL_Rect dest = {pos.x, pos.y, collapsion_ani->w, collapsion_ani->h};
    TextureManager::draw(collapsion_ani->texture, &src, &dest);
}