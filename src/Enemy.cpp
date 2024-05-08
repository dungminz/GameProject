#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"


Enemy::Enemy() {}

Enemy::Enemy(Animation* ani) : enemy_ani(ani) {}

Enemy::Enemy(Animation* _enemy_ani, Animation* _collapsion_ani)
    : enemy_ani(_enemy_ani), collapsion_ani(_collapsion_ani) {}

Enemy::~Enemy() {
    
    if(enemy_spr) delete enemy_spr;
    if(collapsion_spr) delete collapsion_spr;
    enemy_pos.clear();
    collapsion_pos.clear();
}

void Enemy::init() {

    enemy_spr = new Sprite();
    enemy_spr->init(enemy_ani);

    collapsion_spr = new Sprite();
    collapsion_spr->init(collapsion_ani);

    delay_spr = 0;
}


void Enemy::update() {

    delay_spr = ++delay_spr%SPRITE_DELAY;

    for(int i=0; i<enemy_pos.size(); i++) {
        if(!delay_spr) 
            enemy_pos[i].spr = ++enemy_pos[i].spr%enemy_ani->frames;
        enemy_pos[i].x-=enemy_pos[i].speed;
    }

    if(!delay_spr)
        for(int i=0; i<collapsion_pos.size();) {
            collapsion_pos[i].spr++;
            if(collapsion_pos[i].spr>collapsion_ani->frames)
                collapsion_pos.erase(collapsion_pos.begin()+i);
            else i++;
        }
}


void Enemy::render() {

    for(int i=0; i<enemy_pos.size(); i++) {
        SDL_Rect src = enemy_spr->clips[enemy_pos[i].spr];
        SDL_Rect dest = {enemy_pos[i].x, enemy_pos[i].y, enemy_ani->w, enemy_ani->h};
        TextureManager::draw(enemy_ani->texture, &src, &dest);
    }

    for(int i=0; i<collapsion_pos.size(); i++) {
        SDL_Rect src = collapsion_spr->clips[collapsion_pos[i].spr];
        SDL_Rect dest = {collapsion_pos[i].x, collapsion_pos[i].y, collapsion_ani->w, collapsion_ani->h};
        TextureManager::draw(collapsion_ani->texture, &src, &dest);
    }

}