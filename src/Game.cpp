#include "../Header/Game.h"
#include "../Header/Bird.h"
#include "../Header/Enemy.h"
#include "../Header/Background.h"
#include "../Header/CommonFunction.h"

void logErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s : %s", msg, error);
    SDL_Quit();
}

void waitUntilKeyPressed() {
    SDL_Event e;
    while(true) {
        if(SDL_PollEvent(&e) != 0)
            if(e.type == SDL_KEYDOWN || e.type == SDL_QUIT)
                return;
        SDL_Delay(100);
    }
}


SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;


bool Game::leftPressed = false;
bool Game::rightPressed = false;
bool Game::upPressed = false;
bool Game::downPressed = false;


Background *background = nullptr;
Enemy *diamond = nullptr;
Enemy *enemybird = nullptr;
MainBird *mainbird = nullptr;

Pos p = {200, 200, 0};


void Game::init(Animation* _mainbird, Animation* _supportbird, 
        Animation* _diamond, Animation* _diamond_collapsion, 
        Animation* _enemy, Animation* _enemy_collapsion)
{
    
    is_running = true;
    is_enemy=true;

    background = new Background();
    if(background) background->init();
        else logErrorAndExit("CreateBackground", SDL_GetError());

    diamond = new Enemy(_diamond, _diamond_collapsion);
    if(diamond) diamond->init();
        else logErrorAndExit("CreateDiamon", SDL_GetError());
    create_enemy(diamond_pos, 5);

    // enemybird = new Enemy(_enemybird);
    // if(enemybird) enemybird->init();
    //     else logErrorAndExit("CreateEvilbird", SDL_GetError());

    mainbird = new MainBird(_mainbird);
    if(mainbird) mainbird->init();
        else logErrorAndExit("CreateMainBird", SDL_GetError());
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);


    //Render everything
    background->render();

    
    // enemybird->renderEnemy(p);

    for(Pos &pos : diamond_pos) 
        diamond->renderEnemy(pos);
    for(Pos &pos : diamondcollapsion_pos)
        diamond->renderCollapsion(pos);

    mainbird->render();


    SDL_RenderPresent(renderer);
}


void Game::clean() {
    delete background; background = nullptr;
    delete diamond; diamond = nullptr;
    delete mainbird; mainbird = nullptr;
}


void Game::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT: is_running = false; break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:  leftPressed=true;  rightPressed=false; break;
                    case SDLK_RIGHT: rightPressed=true; leftPressed=false;  break;
                    case SDLK_UP:    upPressed=true;    downPressed=false;  break;
                    case SDLK_DOWN:  downPressed=true;  upPressed=false;    break;
                    default: break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:  leftPressed=false;  break;
                    case SDLK_RIGHT: rightPressed=false; break;
                    case SDLK_UP:    upPressed=false;    break;
                    case SDLK_DOWN:  downPressed=false;  break;
                    default: break;
                }
                break;
            default: break;
        }
    }
}


void Game::update() {
    background->update();

    // enemybird->update();
    // enemybird->updateEnemy(p);

    // create_enemy(diamond_pos, 10);
    diamond->update();
    for(Pos &pos : diamond_pos) 
        diamond->updateEnemy(pos);

    for(int pos = 0; pos<diamondcollapsion_pos.size();) {
        diamond->updateCollapsion(diamondcollapsion_pos[pos]);
        if(diamondcollapsion_pos[pos].spr > FLAMES_DIAMONDCOLLAPSION)
            diamondcollapsion_pos.erase(diamondcollapsion_pos.begin()+pos);
        else pos++;
    }
    

    mainbird->update();


// CheckCollision
    if(is_enemy) {

        for(int pos = 0; pos<diamond_pos.size();) {

            SDL_Rect diamond_dest = {diamond_pos[pos].x, diamond_pos[pos].y, DIAMOND_REAL_W, DIAMOND_REAL_H};

            if(checkCollision(mainbird->bird_mouse.getDest(), &diamond_dest)) {

                diamondcollapsion_pos.push_back({diamond_pos[pos].x, diamond_pos[pos].y, 0});
                diamond_pos.erase(diamond_pos.begin()+pos);
            }

            else pos++;
        }

        if(diamond_pos.empty()) is_enemy = false;
    }
}


bool Game::checkCollision(SDL_Rect* _bird, SDL_Rect* _enemy) {
    return SDL_HasIntersection(_bird, _enemy);
}


void Game::create_enemy(std::vector<Pos> &_pos, int numbers) {
    for(int i=1; i<=numbers; i++) {
        int rand_y = DISTANCE_TO_SCREEN + rand()%(SCREEN_HEIGHT - DIAMOND_REAL_H - DISTANCE_TO_SCREEN);
        int rand_spr = rand()%FLAMES_DIAMOND;
        double rand_speed = ENEMY_MIN_SPEED + double(rand()%int(ENEMY_MAX_SPEED*100 - ENEMY_MIN_SPEED*100))/100;
        _pos.push_back({SCREEN_WIDTH, rand_y, rand_spr, rand_speed});
        // std::cerr<<"speed : " << rand_speed<<'\n';
    }
}