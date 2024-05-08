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

bool KeyPressed::mainbird_left = false;
bool KeyPressed::mainbird_right = false;
bool KeyPressed::mainbird_up = false;
bool KeyPressed::mainbird_down = false;
bool KeyPressed::supportbird_left = false;
bool KeyPressed::supportbird_right = false;
bool KeyPressed::supportbird_up = false;
bool KeyPressed::supportbird_down = false;

Background *background = nullptr;
Enemy *diamond = nullptr;
Enemy *enemybird = nullptr;
MainBird *mainbird = nullptr;
SupportBird *supportbird = nullptr;


Game::Game() {}

void Game::init(BackgroundManager* _background, Animation* _mainbird, 
        Animation* _supportBird_flying, Animation* _supportBird_gothit, 
        Animation* _supportBird_shot, Animation* _supportBird_ram, 
        Animation* _supportBird_dead, Animation* _supportBird_henshin, 
        Animation* _supportBird_henshinshot, Animation* _collapsion_by_bird,
        Animation* _enemybird, Animation* _diamond, Animation* _diamond_collapsion)
{
    next_state = GameState::Null;
    is_enemy=true;
    score = 0;
    sp_health = 100;

    KeyPressed::mainbird_left = false;
    KeyPressed::mainbird_right = false;
    KeyPressed::mainbird_up = false;
    KeyPressed::mainbird_down = false;
    KeyPressed::supportbird_left = false;
    KeyPressed::supportbird_right = false;
    KeyPressed::supportbird_up = false;
    KeyPressed::supportbird_down = false;
    
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
}


void Game::clean() {
    
    if(background) delete background;
    if(diamond) delete diamond;
    if(enemybird) enemybird;
    if(mainbird) delete mainbird;
    if(supportbird) delete supportbird;
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
    renderText_Play();

    SDL_RenderPresent(renderer);
}


void Game::renderText_Play() {

    free();
    texture = TextureManager::loadTexture(std::to_string(score), bigfont, white);
    TextureManager::drawText(texture, SCREEN_WIDTH/2, SCREEN_HEIGHT/4);

    free();
    texture = TextureManager::loadTexture("SUPPORT BIRD HEALTH: "+std::to_string(highscore), smallfont, white);
    TextureManager::drawText(texture, 250, SCREEN_HEIGHT-40);
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

        mainbird->handle_events(event);
        supportbird->handle_events(event);
    }
}


void Game::update() {

    background->update();

    // create_enemy(diamond_pos, 10);
    diamond->update();
    // create_enemy(enemybird_pos, 10);
    enemybird->update();
    mainbird->update();
    supportbird->update();

// CheckCollision
    if(checkCollision(mainbird->bird_mouse->getDest(), diamond)) {
        score++;
    }
    if(checkCollision(mainbird->bird_mouse->getDest(), enemybird)) next_state=GameState::End;
    checkCollision(supportbird->spbird_mouse->getDest(), enemybird);

}


bool Game::checkCollision(SDL_Rect* _char_first, SDL_Rect* _char_second) {

    return SDL_HasIntersection(_char_first, _char_second);
}

void cerrrect(SDL_Rect* rect){
    std::cerr<<rect->x<<' '<<rect->y<<' '<<rect->w<<' '<<rect->h<<'\n';
}

bool Game::checkCollision(SDL_Rect* _bird, Enemy* _enemy) {
    
    bool check = false;

    for(int i=0; i<_enemy->enemy_pos.size(); i++) {

        SDL_Rect rect;
        rect.x = _enemy->enemy_pos[i].x;
        rect.y = _enemy->enemy_pos[i].y;
        rect.w = _enemy->enemy_ani->w;
        rect.h = _enemy->enemy_ani->h;

        if(checkCollision(_bird, &rect)) {
            // cerrrect(_bird);
            // cerrrect(&rect);
            check = true;
            _enemy->collapsion_pos.push_back({_enemy->enemy_pos[i].x, _enemy->enemy_pos[i].y, 0});
            _enemy->enemy_pos.erase(_enemy->enemy_pos.begin()+i);
        }
    }
    return check;
}


void Game::create_enemy(Enemy* _enemy, int numbers) {

    for(int i=1; i<=numbers; i++) {

        int rand_y = DISTANCE_TO_SCREEN + rand()%(SCREEN_HEIGHT - _enemy->enemy_ani->h/2 - DISTANCE_TO_SCREEN*2);
        int rand_spr = rand()%_enemy->enemy_ani->frames;
        int rand_speed = ENEMY_MIN_SPEED + rand()%(ENEMY_MAX_SPEED - ENEMY_MIN_SPEED*2);

        _enemy->enemy_pos.push_back({SCREEN_WIDTH, rand_y, rand_spr, rand_speed});
        // std::cerr<<"rand y : " << rand_y<<'\n';
    }
}

void Game::free() {
    if(texture) SDL_DestroyTexture(texture);
}