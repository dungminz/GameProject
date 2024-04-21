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
Bird bird;

void Game::init() {
    is_running = true;
    bgr = TextureManager::loadTexture("bg2.png");
    bird_img = TextureManager::loadTexture("bird.png");
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    //Render everything
    TextureManager::draw(bgr);
    TextureManager::draw(bird_img, 100, 100);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    bgr = NULL;
    bird_img = NULL;
}

void Game::handle_events() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT : is_running = false; break;
            case SDL_KEYDOWN : update(); break;
            default : std::cerr<<"..\n"; break;
        }
    }
}

void Game::update() {
    bird.update();
}