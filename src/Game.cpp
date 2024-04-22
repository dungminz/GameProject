#include <iostream>
#include "../Header/Game.h"
#include "../Header/TextureManager.h"
#include "../Header/Bird.h"

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
bool Game::leftPressed = NULL;
bool Game::rightPressed = NULL;
bool Game::upPressed = NULL;
bool Game::downPressed = NULL;
Bird bird;

void Game::init() {
    is_running = true;
    bgr = TextureManager::loadTexture("bg2.png");
    bird.init();
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    //Render everything
    TextureManager::draw(bgr);
    bird.render();

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyTexture(bgr); bgr = NULL;
    SDL_DestroyTexture(bird_img) ; bird_img = NULL;
}

void Game::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT: is_running = false; break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT: leftPressed=true; rightPressed=false; break;
                    case SDLK_RIGHT: rightPressed=true; leftPressed=false; break;
                    case SDLK_UP: upPressed=true; downPressed=false; break;
                    case SDLK_DOWN: downPressed=true; upPressed=false; break;
                    default: std::cerr<<"key_down\n"; break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT: leftPressed=false; break;
                    case SDLK_RIGHT: rightPressed=false; break;
                    case SDLK_UP: upPressed=false; break;
                    case SDLK_DOWN: downPressed=false; break;
                    default: std::cerr<<"key_up\n"; break;
                }
                break;
            default : std::cerr<<SDL_GetKeyName(event.key.keysym.sym)<<'\n'; break;
        }
    }
}

void Game::update() {
    bird.update();
}