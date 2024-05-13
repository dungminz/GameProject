#include "../Header/Game.h"
#include "../Header/Bird.h"
#include "../Header/Enemy.h"
#include "../Header/Background.h"
#include "../Header/CommonFunction.h"
#include "../Header/Screen.h"

SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;
TTF_Font *Game::bigfont = nullptr;
TTF_Font *Game::smallfont = nullptr;
TTF_Font *Game::mediumfont = nullptr;

Background *background = nullptr;
Enemy *diamond = nullptr;
Enemy *enemybird = nullptr;
MainBird *mainbird = nullptr;
SupportBird *supportbird = nullptr;


Game::Game() {}
Game::~Game() {}


void Game::init(BackgroundManager* _background, Animation* _mainbird, 
        Animation* _supportBird_flying, Animation* _supportBird_gothit, 
        Animation* _supportBird_shot, Animation* _supportBird_ram, 
        Animation* _supportBird_dead, Animation* _supportBird_henshin, 
        Animation* _supportBird_henshinshot, Animation* _collapsion_by_bird,
        Animation* _enemybird, Animation* _diamond, Animation* _diamond_collapsion)
{
    next_state = GameState::Null;
    
    background = new Background(_background);
    if(background) background->init();
        else logErrorAndExit("CreateBackground", SDL_GetError());

    diamond = new Enemy(_diamond, _diamond_collapsion);
    if(diamond) diamond->init();
        else logErrorAndExit("CreateDiamon", SDL_GetError());
    create_enemy(diamond, 5);

    enemybird = new Enemy(_enemybird, _collapsion_by_bird);
    if(enemybird) enemybird->init();
        else logErrorAndExit("CreateEvilbird", SDL_GetError());
    create_enemy(enemybird, 3);

    mainbird = new MainBird(_mainbird);
    if(mainbird) mainbird->init();
        else logErrorAndExit("CreateMainBird", SDL_GetError());
    
    supportbird = new SupportBird(_supportBird_flying, 
                _supportBird_gothit, _supportBird_shot, 
                _supportBird_ram, _supportBird_dead, 
                _supportBird_henshin, _supportBird_henshinshot);
    if(supportbird) supportbird->init();
        else logErrorAndExit("CreateSupportBird", SDL_GetError());
    
    initLogic();
}


void Game::handle_events() {

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        switch(event.type) {

            case SDL_QUIT: 
                next_state=GameState::Quit; 
                break;
            default: break;
        }

        mainbird->bird_mouse->handleEventsMainBird(event);
        supportbird->spbird_mouse->handleEventsSupportBird(event);
    }
}

void Game::render() {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //Render everything
    background->render();

    diamond->render();
    enemybird->render();

    mainbird->render();
    supportbird->render();

    renderLogic();

    SDL_RenderPresent(renderer);
}

void Game::update() {

    background->update();
    
    diamond->update();
    enemybird->update();

    mainbird->bird_mouse->getOtherBird(supportbird->spbird_mouse->curr_bird);
    mainbird->update();

    supportbird->spbird_mouse->getOtherBird(mainbird->bird_mouse->curr_bird);
    supportbird->update();

    updateLogic();
}

void Game::clean() {
    
    free();

    if(background) delete background;
    if(diamond) delete diamond;
    if(enemybird) enemybird;
    if(mainbird) delete mainbird;
    if(supportbird) delete supportbird;
}


void Game::initLogic() {

    time_turn.start();
    time_wave.start();

    score = 0;
    wave_num = 0;
    turn_num = 0;
    turn_diamond = 1;
    turn_enemybird = 1;
}

void Game::updateLogic() {

// CheckCollision
    checkAppear(diamond);
    checkAppear(enemybird);

    if(checkCollision(mainbird->bird_mouse->getDest(), diamond)) {
        score++;
        supportbird->check_sp(BIRD_HEALTH_BY_DIAMOND);
    }

    if(checkCollision(supportbird->spbird_mouse->getDest(), enemybird)) {
        supportbird->check_sp(BIRD_HEALTH_BY_ENEMYBIRD);
    }

    if(checkCollision(mainbird->bird_mouse->getDest(), enemybird)) {
        next_state=GameState::End;
    }

// CheckLogic
    if((time_wave.getTicks()>=TIME_EACH_WAVE && noneEnemy())
    || wave_num==0) 
    {
        ++wave_num;
        turn_num = 0;
        turn_diamond += DIAMOND_EACH_TURN;
        turn_enemybird += ENEMY_BIRD_EACH_TURN;

        time_turn.reset();
        time_wave.reset();
    }
    
    if(time_wave.getTicks()>TIME_TEXT_WAVE_DRAW
    && time_turn.getTicks()>=TIME_EACH_TURN 
    && turn_num<TURNS_EACH_WAVE) 
    {
        ++turn_num;
        create_enemy(diamond, turn_diamond);
        create_enemy(enemybird, turn_enemybird);
        time_turn.reset();
    }
}

void Game::renderLogic() {

    free();
    texture = TextureManager::loadTexture(std::to_string(score), bigfont, white);
    TextureManager::drawText(texture, SCREEN_WIDTH/2, SCREEN_HEIGHT/6);

    free();
    texture = TextureManager::loadTexture("SUPPORT BIRD HEALTH: "+std::to_string(supportbird->health), smallfont, white);
    TextureManager::drawText(texture, 250, SCREEN_HEIGHT-40);

    if(time_wave.getTicks()<TIME_TEXT_WAVE_DRAW) {

        free();
        texture = TextureManager::loadTexture("WAVE "+std::to_string(wave_num), bigfont, yellow);
        TextureManager::drawText(texture, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    }
}

void Game::free() {

    if(texture) SDL_DestroyTexture(texture);
}



bool Game::checkCollision(SDL_Rect* _bird, Enemy* _enemy) {
    
    bool check = false;

    for(int i=0; i<_enemy->enemy_pos.size();) {

        SDL_Rect rect;
        rect.x = _enemy->enemy_pos[i].x;
        rect.y = _enemy->enemy_pos[i].y;
        rect.w = _enemy->enemy_ani->w;
        rect.h = _enemy->enemy_ani->h;

        if(SDL_HasIntersection(_bird, &rect)) {

            check = true;
            _enemy->collapsion_pos.push_back({_enemy->enemy_pos[i].x+_enemy->enemy_ani->w/2, 
                    _enemy->enemy_pos[i].y+_enemy->enemy_ani->h/2, 0});
            _enemy->enemy_pos.erase(_enemy->enemy_pos.begin()+i);
        }
        else i++;
    }
    return check;
}

void Game::checkAppear(Enemy* _enemy) {

    for(int i=0; i<_enemy->enemy_pos.size();) {
        if(_enemy->enemy_pos[i].x+_enemy->enemy_ani->w<0)
            _enemy->enemy_pos.erase(_enemy->enemy_pos.begin()+i);
        else i++;
    }
}

void Game::create_enemy(Enemy* _enemy, int numbers) {

    for(int i=1; i<=numbers; i++) {

        int rand_y = DISTANCE_TO_SCREEN + rand()%(SCREEN_HEIGHT - _enemy->enemy_ani->h - DISTANCE_TO_SCREEN*2);
        int rand_spr = rand()%_enemy->enemy_ani->frames;
        int rand_speed = ENEMY_MIN_SPEED + rand()%(ENEMY_MAX_SPEED - ENEMY_MIN_SPEED);

        _enemy->enemy_pos.push_back({SCREEN_WIDTH, rand_y, rand_spr, rand_speed});
        // std::cerr<<"rand y : " << rand_y<<'\n';
    }
}

bool Game::noneEnemy() {

    if(diamond->enemy_pos.empty()
    && diamond->collapsion_pos.empty()
    && enemybird->enemy_pos.empty()
    && enemybird->collapsion_pos.empty())
        return true;
    return false;
}