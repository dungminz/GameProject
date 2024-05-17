#include "../Header/Enemy.h"
#include "../Header/CommonFunction.h"


Enemy::Enemy() {}


Enemy::Enemy(Animation* _enemy_ani, Animation* _collapsion_ani)
    : enemy_ani(_enemy_ani), collapsion_ani(_collapsion_ani) 
    {}

Enemy::~Enemy() {

    enemy_pos.clear();
    collapsion_pos.clear();
}


void Enemy::init() {

    time_frame.start();
    time_speed.start();
}

void Enemy::update(SDL_Rect* _bird_dest) {

    bird_dest = _bird_dest;

    float dT_frame = time_frame.getTicks();
    int frames_to_update = dT_frame/FRAME_MAX_DELAY_ANIMATION;

    if(frames_to_update>0) {

        for(int i=0; i<enemy_pos.size(); i++) {

            enemy_pos[i].spr += frames_to_update;
            enemy_pos[i].spr %= enemy_ani->frames;
        }

        for(int i=0; i<collapsion_pos.size();) {

            collapsion_pos[i].spr += frames_to_update;
            
            if(collapsion_pos[i].spr>=collapsion_ani->frames)
                collapsion_pos.erase(collapsion_pos.begin()+i);
            else i++;
        }

        time_frame.reset();
    }

    //speed_update per second
    float dT_speed = time_speed.getTicks()/1000.f;

    if(enemy_ani->type == ROCKET)
        for(int i=0; i<enemy_pos.size(); i++) {

            int dy = enemy_pos[i].y - bird_dest->y;
            enemy_pos[i].x-=dT_speed*enemy_pos[i].speed;
            enemy_pos[i].y-=dT_speed*ROCKET_SPEED_TO_BIRD*(dy/abs(dy));
        } 
    else
        for(int i=0; i<enemy_pos.size(); i++) {

            enemy_pos[i].x-=enemy_pos[i].speed*dT_speed;
        }

    time_speed.reset();
}

void Enemy::render() {

    for(int i=0; i<collapsion_pos.size(); i++) {

        SDL_Rect src(collapsion_ani->clips[collapsion_pos[i].spr]);
        SDL_Rect dest({collapsion_pos[i].x, collapsion_pos[i].y, collapsion_ani->w, collapsion_ani->h});
        TextureManager::drawCollaption(collapsion_ani->texture, &src, &dest);
    }

    if(enemy_ani->type == ROCKET) 
        for(int i=0; i<enemy_pos.size(); i++) {

            SDL_Rect src(enemy_ani->clips[enemy_pos[i].spr]);
            SDL_Rect dest({enemy_pos[i].x, enemy_pos[i].y, enemy_ani->w, enemy_ani->h});
            float angle_ = Game::checkAngle(bird_dest, &dest);
            TextureManager::drawAngle(enemy_ani->texture, &src, &dest, angle_);
        }
    else
        for(int i=0; i<enemy_pos.size(); i++) {

            SDL_Rect src(enemy_ani->clips[enemy_pos[i].spr]);
            SDL_Rect dest({enemy_pos[i].x, enemy_pos[i].y, enemy_ani->w, enemy_ani->h});
            TextureManager::draw(enemy_ani->texture, &src, &dest);
        }
}