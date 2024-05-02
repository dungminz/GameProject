#include "../Header/Game.h"
// #include "../Header/DrawTexture.h"
#include "../Header/Bird.h"
#include "../Header/Enemy.h"
#include "../Header/Background.h"

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
Bird *bird = nullptr;

void Game::init() {
    is_running = true;
    is_enemy=true;

    background = new Background();
    if(background) background->init();
        else logErrorAndExit("CreateBackground", SDL_GetError());

    diamond = new Enemy();
    if(diamond) diamond->init();
        else logErrorAndExit("CreateEnemy", SDL_GetError());
    diamond_pos.push_back({1280/2, 720/2, 0});
    diamond_pos.push_back({1280/2+200, 720/2, 2});
    diamond_pos.push_back({1280/2+400, 720/2, 4});

    bird = new Bird();
    if(bird) bird->init();
        else logErrorAndExit("CreateBird", SDL_GetError());
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    //Render everything
    background->render();

    if(is_enemy) 
        for(Pos &pos : diamond_pos) 
            diamond->render(pos.x, pos.y, pos.spr);
    bird->render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    delete background; background = nullptr;
    delete diamond; diamond = nullptr;
    delete bird; bird = nullptr;
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
    if(is_enemy) { 
        diamond->update();
        for(Pos &pos : diamond_pos) 
            diamond->update(pos.spr);
    }
    bird->update();
    if(is_enemy) {
        std::vector<int> to_be_removed;
        for(int pos = 0; pos<diamond_pos.size(); pos++) {
            SDL_Rect diamond_dest = {diamond_pos[pos].x, diamond_pos[pos].y, DIAMOND_REAL_W, DIAMOND_REAL_H};
            if(checkCollision(bird->bird_mouse.getDest(), &diamond_dest)) {
                to_be_removed.push_back(pos);
            }
        }
        for(int i=to_be_removed.size()-1; i>=0; i--) {
            diamond_pos.erase(diamond_pos.begin()+to_be_removed[i]);
        }
        if(diamond_pos.empty()) is_enemy = false;
    }
}

bool Game::checkCollision(SDL_Rect* _bird, SDL_Rect* _enemy) {
    return SDL_HasIntersection(_bird, _enemy);
}