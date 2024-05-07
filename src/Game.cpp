#include "../Header/Game.h"
#include "../Header/Bird.h"
#include "../Header/Enemy.h"
#include "../Header/Background.h"
#include "../Header/CommonFunction.h"
#include "../Header/Screen.h"


SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;

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
    create_enemy(diamond_pos, 5);

    enemybird = new Enemy(_enemybird, _collapsion_by_bird);
    if(enemybird) enemybird->init();
        else logErrorAndExit("CreateEvilbird", SDL_GetError());
    create_enemy(enemybird_pos, 3);

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

    diamond_pos.clear();
    diamondcollapsion_pos.clear();
    enemybird_pos.clear();
    enemybirdcollapsion_pos.clear();
    
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

    for(Pos &pos : diamond_pos) 
        diamond->renderEnemy(pos);
    for(Pos &pos : diamondcollapsion_pos)
        diamond->renderCollapsion(pos);

    for(Pos &pos : enemybird_pos) 
        enemybird->renderEnemy(pos);
    for(Pos &pos : enemybirdcollapsion_pos)
        enemybird->renderCollapsion(pos);
    
    mainbird->render();
    supportbird->render();

    SDL_RenderPresent(renderer);
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
    for(Pos &pos : diamond_pos) 
        diamond->updateEnemy(pos);

    for(int pos = 0; pos<diamondcollapsion_pos.size();) {
        diamond->updateCollapsion(diamondcollapsion_pos[pos]);
        if(diamondcollapsion_pos[pos].spr > FRAMES_DIAMONDCOLLAPSION)
            diamondcollapsion_pos.erase(diamondcollapsion_pos.begin()+pos);
        else pos++;
    }
    
    // create_enemy(enemybird_pos, 10);
    enemybird->update();
    for(Pos &pos : enemybird_pos) 
        enemybird->updateEnemy(pos);

    for(int pos = 0; pos<enemybirdcollapsion_pos.size();) {
        enemybird->updateCollapsion(enemybirdcollapsion_pos[pos]);
        if(enemybirdcollapsion_pos[pos].spr > FRAMES_DIAMONDCOLLAPSION)
            enemybirdcollapsion_pos.erase(enemybirdcollapsion_pos.begin()+pos);
        else pos++;
    }

    mainbird->update();
    supportbird->update();

// CheckCollision
    checkCollision(mainbird->bird_mouse->getDest(), diamond_pos, diamondcollapsion_pos);
    if(checkCollision(mainbird->bird_mouse->getDest(), enemybird_pos, enemybirdcollapsion_pos)) next_state=GameState::End;
    checkCollision(supportbird->spbird_mouse->getDest(), enemybird_pos, enemybirdcollapsion_pos);

}


bool Game::checkCollision(SDL_Rect* _char_first, SDL_Rect* _char_second) {

    return SDL_HasIntersection(_char_first, _char_second);
}


bool Game::checkCollision(SDL_Rect* _bird, std::vector<Pos> &enemy_pos, std::vector<Pos> &collapsion_pos) {

    bool check = false;

    for(int pos = 0; pos<enemy_pos.size();) {

        SDL_Rect enemy_dest = {enemy_pos[pos].x, enemy_pos[pos].y, DIAMOND_REAL_W, DIAMOND_REAL_H};

        if(checkCollision(_bird, &enemy_dest)) {

            collapsion_pos.push_back({enemy_pos[pos].x, enemy_pos[pos].y, 0});
            enemy_pos.erase(enemy_pos.begin()+pos);
            check = true;
        }

        else pos++;
    }

    if(enemy_pos.empty()) is_enemy = false;

    return check;
}


void Game::create_enemy(std::vector<Pos> &_pos, int numbers) {

    for(int i=1; i<=numbers; i++) {

        int rand_y = DISTANCE_TO_SCREEN + rand()%(SCREEN_HEIGHT- DISTANCE_TO_SCREEN);
        int rand_spr = rand()%FRAMES_DIAMOND;
        double rand_speed = ENEMY_MIN_SPEED + double(rand()%int(ENEMY_MAX_SPEED*100 - ENEMY_MIN_SPEED*100))/100;

        _pos.push_back({SCREEN_WIDTH, rand_y, rand_spr, rand_speed});
        // std::cerr<<"speed : " << rand_speed<<'\n';
    }
}
