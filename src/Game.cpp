#include "../Header/Game.h"
#include "../Header/TextureManager.h"

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

void Game::init() {
    bgr = TextureManager::loadTexture("bg2.png");
    bird = TextureManager::loadTexture("bird.png");
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    //Render everything
    TextureManager::draw(bgr);
    TextureManager::draw(bird, 100, 100);

    SDL_RenderPresent(renderer);
}

void Game::render2() {
    SDL_RenderClear(renderer);
    
    //Render everything
    TextureManager::draw(bgr);
    TextureManager::draw(bird, 200, 200);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    bgr = NULL;
    bird = NULL;
}